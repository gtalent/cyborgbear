/*
 * Copyright 2013-2014 gtalent2@gmail.com
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//Generated Code



#include "string.h"
#include "Model.hpp"

using namespace models;
using std::stringstream;

Model1::Model1() {
	this->Field1 = "";
	for (int i = 0; i < 4; this->Field3[i++] = 0);
}

cyborgbear::Error Model1::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Field1");
		{
			if (cyborgbear::isString(obj0)) {
				this->Field1 = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Field2");
		{
			retval |= this->Field2.loadJsonObj(obj0);
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Field3");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isInt(obj1)) {
							this->Field3[i] = cyborgbear::toInt(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Field4");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Field4.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					if (!cyborgbear::isNull(obj1)) {
						if (cyborgbear::isArray(obj1)) {
							cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
							unsigned int size = cyborgbear::arraySize(array1);
							this->Field4[i].resize(size);
							for (unsigned int ii = 0; ii < size; ii++) {
								cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
								{
									if (cyborgbear::isString(obj2)) {
										this->Field4[i][ii] = cyborgbear::toString(obj2);
									} else {
										if (cyborgbear::isNull(obj2)) {
											retval |= cyborgbear::Error_MissingField;
										} else {
											retval |= cyborgbear::Error_TypeMismatch;
										}
									}
								}
							}
						} else {
							retval |= cyborgbear::Error_TypeMismatch;
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Field5");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->Field5[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	return retval;
}

cyborgbear::JsonValOut Model1::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Field1);
		cyborgbear::objSet(obj, "Field1", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Field2.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Field2", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < 4; i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Field3[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Field3", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Field4.size(); i++) {
			cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->Field4[i].size(); ii++) {
				cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Field4[i][ii]);
				cyborgbear::arrayAdd(out1, out0);
				cyborgbear::decref(out0);
			}
			cyborgbear::arrayAdd(out2, out1);
			cyborgbear::decref(out1);
		}
		cyborgbear::objSet(obj, "Field4", out2);
		cyborgbear::decref(out2);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, string >::iterator n = this->Field5.begin(); n != this->Field5.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Field5[n->first]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Field5", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Model1::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Model1::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}
