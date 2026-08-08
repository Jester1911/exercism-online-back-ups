package circularbuffer

import (
	"errors"
)

// Implement a circular buffer of bytes supporting both overflow-checked writes
// and unconditional, possibly overwriting, writes.
//
// We chose the provided API so that Buffer implements io.ByteReader
// and io.ByteWriter and can be used (size permitting) as a drop in
// replacement for anything using that interface.

// Define the Buffer type here.
type Buffer struct {
	bytes []byte // Data
	head  int    // Points to index where first element is
	tail  int    // Poinst to index where next element goes
	count int
}

// NewBuffer allocates and returns a pointer to a new buffer.
func NewBuffer(size int) *Buffer {
	return &Buffer{
		bytes: make([]byte, size),
		head:  0,
		tail:  0,
		count: 0}
}

// ReadByte returns the oldest data from the buffer, which resides at the current head. If the
// buffer is empty, ReadByte raises an error.
func (b *Buffer) ReadByte() (byte, error) {
	if b.length() == 0 {
		return 0, errors.New("cannot read from empty buffer")
	}
	result := b.bytes[b.head]
	b.advanceHead()
	b.count--
	return result, nil
}

// WriteByte writes new data to the buffer, which resides at the current tail. If the buffer is
// full, WriteByte raises an error.
func (b *Buffer) WriteByte(c byte) error {
	if b.length() == b.capacity() {
		return errors.New("cannot write to full buffer")
	}
	b.bytes[b.tail] = c
	b.advanceTail()
	b.count++
	return nil
}

// Overwrite functions like WriteByte if the buffer is not full. If full, Overwrite pushes out
// the oldest data (old head) and adds the newest data (new tail).
func (b *Buffer) Overwrite(c byte) {
	if b.length() == b.capacity() {
		b.bytes[b.head] = c
		b.advanceHead()
		b.advanceTail()
	} else {
		b.WriteByte(c)
	}
}

// Reset leaves all data in place (e.g. does not clear byte values) and resets the buffers tracking
// to the same state as if it were a new buffer.
func (b *Buffer) Reset() {
	b.head, b.tail, b.count = 0, 0, 0
}

// capacity returns the total allocated size of the buffer.
func (b *Buffer) capacity() int {
	return cap(b.bytes)
}

// length returns how many active bytes are in the buffer.
func (b *Buffer) length() int {
	return b.count
}

// advance Head increments the index position of the current head and handles wraparound if
// advancing the head resultsin going past the last index position.
func (b *Buffer) advanceHead() {
	if b.head+1 == b.capacity() {
		b.head = 0
		return
	}
	b.head++
}

// advanceTail increments the index position of the current tail and handles wraparound if
// advancing the tail results in going past the last index position.
func (b *Buffer) advanceTail() {
	if b.tail+1 == b.capacity() {
		b.tail = 0
		return
	}
	b.tail++
}
