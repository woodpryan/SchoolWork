/**********************************************\
 * MArray.h
 *
 * Classification: Unclassified
 *
 * Classification verified by Mike Wood
 *
 * Copyright IroquoiSystems, Inc. (c) 2013
 **********************************************/

#ifndef _ICM_MARRAY_H
#define _ICM_MARRAY_H

#include <cstddef>

#include "Index.h"
#include "Shape.h"

namespace isiSim {
namespace common {
namespace marray {

typedef Shape::Extent Extent;

template<typename T>
class MArray
{
public:
    MArray(const MArray<T>& src);

    explicit MArray(const Extent* ext, const size_t numDims);

    explicit MArray(const Extent* ext, const size_t numDims, T fill);

    explicit MArray(const Shape& shape);

    explicit MArray(const Shape& shape, T fill);

    virtual ~MArray();

    MArray<T>& operator=(const MArray<T>& src);

    Index first() const;

    Index generateIndex() const;

    Extent getDimExtent(size_t dim) const;

    size_t getInternalDimIndex(size_t dim) const;

    const T getItem() const;

    const T getItem(const Index& ndx) const;

    size_t getNumDimensions() const;

    size_t getSize() const;

    Shape getShape() const;

    Index last() const;

    void setInternalDimIndex(const size_t dim, const size_t ndx);

    void setItem(T item);

    void setItem(T item, const Index& ndx);

private:
    std::vector<T> m_Items;
    Index*         m_InternalIndex;
    Shape          m_Shape;
};

template<typename T>
inline MArray<T>::MArray(const MArray<T>& src) :
    m_Shape(src.getShape())
{
    m_InternalIndex = new Index(m_Shape);
    *this = src;
}

template<typename T>
inline MArray<T>::MArray(const Extent* ext, const size_t numDims) :
    m_Shape(ext, numDims)
{
    try
    {
        m_Items.resize(getSize());
    }
    catch(std::exception)
    {
        throw exception::AllocationError("Failed to allocate space for container");
    }

    m_InternalIndex = new Index(m_Shape);
}

template<typename T>
inline MArray<T>::MArray(const Extent* ext, const size_t numDims, T fill) :
    m_Shape(ext, numDims)
{
    try
    {
        m_Items.resize(getSize(), fill);
    }
    catch(std::exception)
    {
        throw exception::AllocationError("Failed to allocate space for container");
    }

    m_InternalIndex = new Index(m_Shape);
}

template<typename T>
inline MArray<T>::MArray(const Shape& shape) :
    m_Shape(shape)
{
    try
    {
        m_Items.resize(getSize());
    }
    catch(std::exception)
    {
        throw exception::AllocationError("Failed to allocate space for container");
    }

    m_InternalIndex = new Index(m_Shape);
}

template<typename T>
inline MArray<T>::MArray(const Shape& shape, T fill) :
    m_Shape(shape)
{
    try
    {
        m_Items.resize(getSize(), fill);
    }
    catch(std::exception)
    {
        throw exception::AllocationError("Failed to allocate space for container");
    }

    m_InternalIndex = new Index(m_Shape);
}

template<typename T>
inline MArray<T>::~MArray()
{
    delete m_InternalIndex;
}

template<typename T>
inline MArray<T>& MArray<T>::operator=(const MArray<T>& src)
{
    if(src.m_Shape != m_Shape)
    {
        throw exception::InvalidParameter("Attempted to copy an MArray with incorrect shape");
    }

    m_Items = src.m_Items;
    *m_InternalIndex = *src.m_InternalIndex;

    return *this;
}

template<typename T>
inline Index MArray<T>::first() const
{
    // This could change if major order modification is implemented.
    return generateIndex();
}

template<typename T>
inline Index MArray<T>::generateIndex() const
{
    return Index(m_Shape);
}

template<typename T>
inline Extent MArray<T>::getDimExtent(size_t dim) const
{
    return m_Shape.getDimExtent(dim);
}

template<typename T>
inline size_t MArray<T>::getInternalDimIndex(size_t dim) const
{
    return m_InternalIndex->getDimIndex(dim);
}

template<typename T>
inline const T MArray<T>::getItem() const
{
    size_t flatNdx = m_InternalIndex->getFlatIndex();

    // Don't allow the container to be resized for now
    if(flatNdx >= getSize())
    {
        throw exception::IndexRangeError();
    }

    return m_Items[flatNdx];
}

template<typename T>
inline const T MArray<T>::getItem(const Index& ndx) const
{
    size_t flatNdx = ndx.getFlatIndex();

    // Don't allow the container to be resized for now
    if(flatNdx >= getSize())
    {
        throw exception::IndexRangeError();
    }

    return m_Items[flatNdx];
}

template<typename T>
inline size_t MArray<T>::getNumDimensions() const
{
    return m_Shape.getNumDimensions();
}

template<typename T>
inline Shape MArray<T>::getShape() const
{
    return m_Shape;
}


template<typename T>
inline size_t MArray<T>::getSize() const
{
    return m_Shape.getSize();
}

template<typename T>
inline Index MArray<T>::last() const
{
    Index ndx = generateIndex();

    for(size_t dim = 0; dim < ndx.getNumDimensions(); ++dim)
    {
        ndx.setDimIndex(dim, m_Shape.getDimExtent(dim)-1);
    }

    return ndx;
}

template<typename T>
inline void MArray<T>::setInternalDimIndex(const size_t dim, const size_t ndx)
{
    m_InternalIndex->setDimIndex(dim, ndx);
}

template<typename T>
inline void MArray<T>::setItem(T item)
{
    size_t flatNdx = m_InternalIndex->getFlatIndex();

    // Don't allow the container to be resized for now
    if(flatNdx >= getSize())
    {
        throw exception::IndexRangeError("Attempted to index beyond extent");
    }

    m_Items[flatNdx] = item;
}

template<typename T>
inline void MArray<T>::setItem(T item, const Index& ndx)
{
    size_t flatNdx = ndx.getFlatIndex();

    // Don't allow the container to be resized for now
    if(flatNdx >= getSize())
    {
        throw exception::IndexRangeError("Attempted to index beyond extent");
    }

    m_Items[flatNdx] = item;
}

}}} // namespace
#endif // _ICM_MARRAY_H
