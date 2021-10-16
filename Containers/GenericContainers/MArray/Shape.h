/**********************************************\
 * Shape.h
 *
 * Classification: Unclassified
 *
 * Classification verified by Mike Wood
 *
 * Copyright IroquoiSystems, Inc. (c) 2013
 **********************************************/

#ifndef _ICM_SHAPE_H
#define _ICM_SHAPE_H

#include <cstddef>
#include <vector>

namespace isiSim {
namespace common {
namespace marray {

class Shape
{
public:
    typedef size_t Extent;

    explicit Shape(const Extent* ext, const size_t numDims);

    explicit Shape(const std::vector<Extent>& dimExts);

    bool operator==(const Shape& ref) const;

    bool operator!=(const Shape& ref) const;

    size_t getNumDimensions() const;

    size_t getDimCapacity(const size_t dim) const;

    size_t getDimExtent(const size_t dim) const;

    size_t getSize() const;

private:
    struct ExtentProperty
    {
        Extent _extent;
        size_t _capacity;
    };

    typedef std::vector<ExtentProperty>    ShapeContainer;
    typedef ShapeContainer::const_iterator ShapeContainerConstIter;
    typedef ShapeContainer::iterator       ShapeContainerIter;

    ShapeContainer m_Extents;
};

inline Shape::Shape(const Extent* ext, const size_t numDims)
{
    m_Extents.resize(numDims);

    for(size_t i = 0; i < numDims; ++i)
    {
        ExtentProperty prop = {ext[i], 1};

        for(size_t j = i + 1; j < numDims; ++j)
        {
            prop._capacity *= ext[j];
        }

        m_Extents[i] = prop;
    }
}

inline Shape::Shape(const std::vector<Extent>& dimExts)
{
    m_Extents.resize(dimExts.size());

    for(size_t i = 0; i < dimExts.size(); ++i)
    {
        ExtentProperty prop = {dimExts[i], 1};

        for(size_t j = i + 1; j < dimExts.size(); ++j)
        {
            prop._capacity *= dimExts[j];
        }

        m_Extents[i] = prop;
    }
}

inline bool Shape::operator==(const Shape& ref) const
{
    if(ref.getNumDimensions() != getNumDimensions())
    {
        return false;
    }

    for(size_t dim = 0; dim < m_Extents.size(); ++dim)
    {
        if(ref.m_Extents[dim]._extent != m_Extents[dim]._extent)
        {
            return false;
        }
    }

    return true;
}

inline bool Shape::operator!=(const Shape& ref) const
{
    return !operator==(ref);
}

inline size_t Shape::getNumDimensions() const
{
    return m_Extents.size();
}

inline size_t Shape::getDimCapacity(const size_t dim) const
{
    if(m_Extents.size() > dim)
    {
        return m_Extents[dim]._capacity;
    }

    return 0;
}

inline size_t Shape::getDimExtent(const size_t dim) const
{
    if(m_Extents.size() > dim)
    {
        return m_Extents[dim]._extent;
    }

    return 0;
}

inline size_t Shape::getSize() const
{
    size_t size = 1;

    if(!m_Extents.size())
    {
        return 0;
    }

    for(ShapeContainerConstIter i = m_Extents.begin(); i != m_Extents.end(); ++i)
    {
        size *= (*i)._extent;
    }

    return size;
}

}}} // namespace

#endif // SHAPE_H
