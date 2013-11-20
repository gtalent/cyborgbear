cpp:
	../cyborgbear -i model.cy -bi Model.hpp -bn models -o Models2 -n models2
	c++ main.cpp Model.cpp -o main -ljansson -lboost_serialization
go:
	../cyborgbear -i model.cy -o models.go -t go
	go build
