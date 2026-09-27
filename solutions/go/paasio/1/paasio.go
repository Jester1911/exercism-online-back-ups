package paasio

import (
	"io"
	"sync"
)

type readCounter struct {
	reader io.Reader
	mu     sync.Mutex
	bytes  int64
	nops   int
}

type writeCounter struct {
	writer io.Writer
	mu     sync.Mutex
	bytes  int64
	nops   int
}

type readWriteCounter struct {
	readCounter
	writeCounter
}

func NewWriteCounter(writer io.Writer) WriteCounter {
	return &writeCounter{writer: writer}
}

func NewReadCounter(reader io.Reader) ReadCounter {
	return &readCounter{reader: reader}
}

func NewReadWriteCounter(readwriter io.ReadWriter) ReadWriteCounter {
	return &readWriteCounter{
		readCounter:  readCounter{reader: readwriter},
		writeCounter: writeCounter{writer: readwriter},
	}
}

func (rc *readCounter) Read(p []byte) (int, error) {
	n, err := rc.reader.Read(p)
	rc.mu.Lock()
	rc.nops++
	rc.bytes += int64(n)
	rc.mu.Unlock()
	if err != nil {
		return 0, err
	}
	return n, nil
}

func (rc *readCounter) ReadCount() (int64, int) {
	rc.mu.Lock()
	defer rc.mu.Unlock()
	return rc.bytes, rc.nops
}

func (wc *writeCounter) Write(p []byte) (int, error) {
	n, err := wc.writer.Write(p)
	wc.mu.Lock()
	wc.nops++
	wc.bytes += int64(n)
	wc.mu.Unlock()
	if err != nil {
		return n, err
	}
	return n, nil
}

func (wc *writeCounter) WriteCount() (int64, int) {
	wc.mu.Lock()
	defer wc.mu.Unlock()
	return wc.bytes, wc.nops
}
