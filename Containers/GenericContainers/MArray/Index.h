/**********************************************\
 * Index.h
 *
 * Classification: Unclassified
 *
 * Classification verified by Mike Wood
 *
 * Copyright IroquoiSystems, Inc. (c) 2013
 **********************************************/

#ifndef _ICM_INDEX_H
#define _ICM_INDEX_H

#include <sstream>
#include <vector>

#include <utility/StringUtils.h>
#include "exception/Exception.h"

#include "Shape.h"

namespace isiSim {
namespace common {
namespace marray {

class Index
{
public:
    Index(const Index& src);

    explicit Index(const Shape::Extent* ext, const size_t numDims);

    explicit Index(const std::vector<Shape::Extent>& dimExts);

    explicit Index(const Shape& shape);

    ~Index();

    Index& operator=(const Index& src);

    Index& operator=(const std::string& str);

    Index& operator=(const char* str);

    bool operator==(const Index& ref) const;

    bool operator!=(const Index& ref) const;

    bool operator<(const Index& ref) const;

    bool operator>(const Index& ref) const;

    bool operator<=(const Index& ref) const;

    bool operator>=(const Index& ref) const;

    /**
    Pre-decrement operator.
    */
    Index& operator--();

    /**
    Post-decrement operator.
    */
    Index operator--(int);

    /**
    Pre-increment operator.
    */
    Index& operator++();

    /**
    Post-increment operator.
    */
    Index operator++(int);

    std::string asString() const;

    size_t getDimIndex(const size_t dim) const;

    size_t getFlatIndex() const;

    size_t getNumDimensions() const;

    bool npos() const;

    void setDimIndex(const size_t dim, const size_t index);

private:
    void decrementDim(const size_t dim);

    void incrementDim(const size_t dim);

    Shape*              m_Shape;
    std::vector<size_t> m_IndexVec;
    bool                m_Npos;
};

inline Index::Index(const Index& src)
{
    m_Shape    = new Shape(*src.m_Shape);
    m_IndexVec = src.m_IndexVec;
    m_Npos     = src.m_Npos;
}

inline Index::Index(const Shape::Extent* ext, const size_t numDims)
{
    if(NULL == ext)
    {
        throw exception::NullPointer();
    }

    m_Shape = new Shape(ext, numDims);
    m_Npos  = false;
    m_IndexVec.resize(getNumDimensions(), 0);
}

inline Index::Index(const std::vector<Shape::Extent>& dimExts)
{
    m_Shape = new Shape(dimExts);
    m_Npos  = false;
    m_IndexVec.resize(getNumDimensions(), 0);
}

inline Index::Index(const Shape& shape)
{
    m_Shape = new Shape(shape);
    m_Npos  = false;
    m_IndexVec.resize(getNumDimensions(), 0);
}

inline Index::~Index()
{
    delete m_Shape;
}

inline Index& Index::operator=(const Index& src)
{
    if(src.getNumDimensions() != getNumDimensions())
    {
        throw exception::InvalidParameter("Source index is not the same shape as the target index");
    }

    for(size_t dim = 0; dim < getNumDimensions(); ++dim)
    {
        if(src.m_IndexVec[dim] >= m_Shape->getDimExtent(dim))
        {
            throw exception::IndexRangeError("Attempted to index beyond extent");
        }
    }

    // Only modify the values after everything checks out
    for(size_t dim = 0; dim < getNumDimensions(); ++dim)
    {
        m_IndexVec[dim] = src.m_IndexVec[dim];
    }

    m_Npos = src.m_Npos;

    return *this;
}

inline Index& Index::operator=(const std::string& str)
{
    utility::StringList slist;
    size_t dim = 0;

    if(str[0] == '[' && str[str.size()-1] == ']')
    {
        slist = utility::StringUtils::tokenize(str.substr(1, str.size()-2), "][");
    }
    else
    {
        slist = utility::StringUtils::tokenize(str, ",");
    }

    if(slist.size() != getNumDimensions())
    {
        throw exception::InvalidParameter("Index list does not contain the correct number of items");
    }

    for(utility::StringList::StringListConstIter iter = slist.begin(); iter != slist.end(); ++iter)
    {
        unsigned long val;

        try
        {
            val = utility::StringUtils::toNumber<unsigned long>(*iter);
        }
        catch(exception::Exception& e)
        {
            throw exception::InvalidParameter("Index must be unsigned integral");
        }

        if(val >= m_Shape->getDimExtent(dim))
        {
            throw exception::IndexRangeError("Attempted to index beyond extent");
        }

        m_IndexVec[dim] = val;
        ++dim;
    }

    m_Npos = false;

    return *this;
}

inline Index& Index::operator=(const char* str)
{
    return operator=(std::string(str));
}

inline bool Index::operator==(const Index& ref) const
{
    if(ref.getNumDimensions() != getNumDimensions())
    {
        return false;
    }

    for(size_t dim = 0; dim < getNumDimensions(); ++dim)
    {
        if(ref.m_IndexVec[dim] != m_IndexVec[dim])
        {
            return false;
        }
    }

    return true;
}

inline bool Index::operator!=(const Index& ref) const
{
    return !operator==(ref);
}

inline bool Index::operator<(const Index& ref) const
{
    if(ref.getNumDimensions() != getNumDimensions())
    {
        throw exception::InvalidParameter("Attempt to compare Indexes of differing shapes");
    }

    for(size_t dim = 0; dim < getNumDimensions(); ++dim)
    {
        if(m_IndexVec[dim] < ref.m_IndexVec[dim])
        {
            return true;
        }
    }

    return false;
}

inline bool Index::operator>(const Index& ref) const
{
    return !(operator<=(ref));
}

inline bool Index::operator<=(const Index& ref) const
{
    if(operator==(ref))
    {
        return true;
    }

    return operator<(ref);
}

inline bool Index::operator>=(const Index& ref) const
{
    if(operator==(ref))
    {
        return true;
    }

    return operator>(ref);
}

inline Index& Index::operator--()
{
    decrementDim(getNumDimensions()-1);

    return *this;
}

inline Index Index::operator--(int)
{
    Index copy(*this);

    decrementDim(getNumDimensions()-1);

    return copy;
}

inline Index& Index::operator++()
{
    incrementDim(getNumDimensions()-1);

    return *this;
}

inline Index Index::operator++(int)
{
    Index copy(*this);

    incrementDim(getNumDimensions()-1);

    return copy;
}

inline std::string Index::asString() const
{
    std::ostringstream ndxString;

    if(m_Npos)
    {
        return std::string("npos");
    }

    for(size_t dim = 0; dim < getNumDimensions(); ++dim)
    {
        ndxString << "[" << m_IndexVec[dim] << "]";
    }

    return ndxString.str();
}

inline size_t Index::getDimIndex(const size_t dim) const
{
    if(dim >= getNumDimensions())
    {
        throw exception::IndexRangeError("Requested index for invalid dim");
    }

    return m_IndexVec[dim];
}

inline size_t Index::getFlatIndex() const
{
    size_t flatndx = 0;

    if(m_Npos)
    {
        throw exception::IndexRangeError("Attempted to get flat index for Index that is out of range.");
    }

    for(size_t i = 0; i < getNumDimensions(); ++i)
    {
        flatndx += m_IndexVec[i] * m_Shape->getDimCapacity(i);
    }

    return flatndx;
}

inline size_t Index::getNumDimensions() const
{
    return m_Shape->getNumDimensions();
}

inline bool Index::npos() const
{
    return m_Npos;
}

inline void Index::setDimIndex(const size_t dim, const size_t index)
{
    if(dim >= getNumDimensions())
    {
        throw exception::IndexRangeError("Attempted to set index for invalid dim");
    }

    if(index >= m_Shape->getDimExtent(dim))
    {
        throw exception::IndexRangeError("Attempted to index beyond extent");
    }

    m_IndexVec[dim] = index;
}

inline void Index::decrementDim(const size_t dim)
{
    if(dim >= getNumDimensions())
    {
        throw exception::IndexRangeError("Attempted to increment invalid dimension index");
    }

    size_t dimNdx = m_IndexVec[dim];

    if(dimNdx == 0)
    {
        if(dim != 0)
        {
            decrementDim(dim - 1);
        }
        else
        {
            m_Npos = true;
        }
    }
    else
    {
        --m_IndexVec[dim];

        for(size_t i = dim+1; i < getNumDimensions(); ++i)
        {
            m_IndexVec[i] = m_Shape->getDimExtent(i)-1;
        }
    }
}

inline void Index::incrementDim(const size_t dim)
{
    if(dim >= getNumDimensions())
    {
        throw exception::IndexRangeError("Attempted to increment invalid dimension index");
    }

    size_t dimNdx = m_IndexVec[dim];

    if(m_Shape->getDimExtent(dim) <= dimNdx+1)
    {
        if(dim != 0)
        {
            incrementDim(dim - 1);
        }
        else
        {
            m_Npos = true;
        }
    }
    else
    {
        ++m_IndexVec[dim];

        for(size_t i = dim+1; i < getNumDimensions(); ++i)
        {
            m_IndexVec[i] = 0;
        }
    }
}

}}} // namespace

#endif
