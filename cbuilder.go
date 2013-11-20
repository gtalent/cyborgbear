/*
   Copyright 2013 gtalent2@gmail.com

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
package main

import (
	"./parser"
	"io/ioutil"
)

type Cpp struct {
	hpp       string
	baseNs    string
	namespace string
	lowerCase bool
}

func NewCOut(include, baseNs, namespace string, lowerCase bool) *Cpp {
	out := new(Cpp)
	out.lowerCase = lowerCase
	out.namespace = namespace
	out.baseNs = baseNs
	out.hpp = `#include <string>
#include <sstream>
#include "` + include + `"

namespace ` + namespace + ` {

namespace cyborgbear = ` + baseNs + `::cyborgbear;

}

`
	return out
}

func (me *Cpp) write(outFile string) string {
	return me.hpp
}

func (me *Cpp) writeFile(outFile string) error {
	var err error
	err = ioutil.WriteFile(outFile+".hpp", []byte(me.hpp), 0644)
	if err != nil {
		return err
	}
	return err
}

func (me *Cpp) addVar(v string, index []parser.VarType) {
}

func (me *Cpp) addClass(v string) {
	me.hpp += `
namespace ` + me.namespace + ` {

class ` + v + `: public ` + me.baseNs + `::` + v + ` {
};

}

namespace boost {
namespace serialization {

template<class Archive>
void serialize(Archive &ar, ` + me.namespace + "::" + v + ` &model, const unsigned int) {
	ar & boost::serialization::base_object<` + me.baseNs + `::` + v + `>(model);
}

}
}
`
}

func (me *Cpp) closeClass(v string) {
}
