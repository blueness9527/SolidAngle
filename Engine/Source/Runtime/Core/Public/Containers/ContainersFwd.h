#pragma once
class FDefaultAllocator;
class FDefaultSetAllocator;

class YString;

template<typename KeyType, typename ValueType> class TPair;
template<typename T, typename Allocator = FDefaultAllocator> class TArray;
template<typename T> class TTransArray;
template<typename KeyType, typename ValueType, bool bInAllowDuplicateKeys> struct TDefaultMapKeyFuncs;
template<typename KeyType, typename ValueType, typename SetAllocator = FDefaultSetAllocator, typename KeyFuncs = TDefaultMapKeyFuncs<KeyType, ValueType, false> > class TMap;
template<typename KeyType, typename ValueType, typename SetAllocator = FDefaultSetAllocator, typename KeyFuncs = TDefaultMapKeyFuncs<KeyType, ValueType, true > > class TMultiMap;
