// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
    private Iterator<Integer> iterator;
    private Integer peekedElement;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    this.iterator = iterator;
        this.peekedElement = null;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if (peekedElement == null) {
            if (!iterator.hasNext()) {
                throw new java.util.NoSuchElementException();
            }
            peekedElement = iterator.next();
        }
        return peekedElement;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if (peekedElement != null) {
            Integer toReturn = peekedElement;
            peekedElement = null;
            return toReturn;
        }
        if (!iterator.hasNext()) {
            throw new java.util.NoSuchElementException();
        }
        return iterator.next();
	}
	
	@Override
	public boolean hasNext() {
	    return peekedElement != null || iterator.hasNext();
	}
}