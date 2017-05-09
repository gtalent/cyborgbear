build:
	go build -o cyborgjson
install: build
	mkdir -p $(GOPATH)/bin
	cp cyborgjson $(GOPATH)/bin
fmt:
	make -C parser
	go fmt
