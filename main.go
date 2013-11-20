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
	"flag"
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	out := flag.String("o", "stdout", "File or file set(languages with header files) to write the output to")
	in := flag.String("i", "", "The model file to generate JSON serialization code for")
	namespace := flag.String("n", "models", "Namespace for the models")
	baseNs := flag.String("bn", "models", "Namespace for the base models")
	baseInclude := flag.String("bi", "models", "Include file for the base models")
	lowerCase := flag.Bool("lc", false, "Make variable names lowercase in output models")
	version := flag.Bool("v", false, "version")
	flag.Parse()

	if *version {
		fmt.Println("cyborgbear version " + cyborgbear_version)
		return
	}
	parseFile(*in, *baseInclude, *out, *baseNs, *namespace, *lowerCase)
}

func parseFile(path, baseInclude, outFile, baseNs, namespace string, lowerCase bool) {
	ss, err := ioutil.ReadFile(path)
	if err != nil {
		fmt.Println("Could not find or open specified model file")
		os.Exit(1)
	}
	input := string(ss)

	var out Out
	out = NewCOut(baseInclude, baseNs, namespace, lowerCase)

	models, err := parser.Parse(input)
	if err != nil {
		fmt.Println(err)
		os.Exit(2)
		return
	} else {
		for _, v := range models {
			out.addClass(v.Name)
			for _, vv := range v.Vars {
				out.addVar(vv.Name, vv.Type)
			}
			out.closeClass(v.Name)
		}

		if outFile == "stdout" {
			fmt.Print(out.write(""))
		} else {
			out.writeFile(outFile)
		}
	}
}
