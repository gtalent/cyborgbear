//Generated Code

#include <fstream>
#include "Model.hpp"

using namespace models;
using namespace models::cyborgjson;

string models::cyborgjson::version = "2.0.0-beta1";

int Model::readJsonFile(string path) {
	try {
		std::ifstream in;
		in.open(cyborgjson::toStdString(path).c_str());
		if (in.is_open()) {
			std::string json((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
			in.close();
			return fromJson(cyborgjson::toString(json));
		}
	} catch (...) {
	}
	return cyborgjson::Error_CouldNotAccessFile;
}

void Model::writeJsonFile(string path, cyborgjson::JsonSerializationSettings sttngs) {
	std::ofstream out;
	out.open(cyborgjson::toStdString(path).c_str());
	std::string json = cyborgjson::toStdString(toJson(sttngs));
	out << json << "\0";
	out.close();
}

int Model::fromJson(string json) {
	cyborgjson::JsonValOut obj = cyborgjson::read(json);
	cyborgjson::Error retval = loadJsonObj(obj);
	cyborgjson::decref(obj);
	return retval;
}

string Model::toJson(cyborgjson::JsonSerializationSettings sttngs) {
	cyborgjson::JsonValOut val = buildJsonObj();
	cyborgjson::JsonObjOut obj = cyborgjson::toObj(val);
	return cyborgjson::write(obj, sttngs);
}

unknown::unknown() {
}

unknown::unknown(Model *v) {
	set(v);
}

unknown::unknown(bool v) {
	set(v);
}

unknown::unknown(int v) {
	set(v);
}

unknown::unknown(double v) {
	set(v);
}

unknown::unknown(string v) {
	set(v);
}

unknown::~unknown() {
}

cyborgjson::Error unknown::loadJsonObj(cyborgjson::JsonVal obj) {
	cyborgjson::JsonObjOut wrapper = cyborgjson::newJsonObj();
	cyborgjson::objSet(wrapper, "Value", obj);
	m_data = cyborgjson::write(wrapper, cyborgjson::Compact);
	if (cyborgjson::isBool(obj)) {
		m_type = cyborgjson::Bool;
	} else if (cyborgjson::isInt(obj)) {
		m_type = cyborgjson::Integer;
	} else if (cyborgjson::isDouble(obj)) {
		m_type = cyborgjson::Double;
	} else if (cyborgjson::isString(obj)) {
		m_type = cyborgjson::String;
	} else if (cyborgjson::isObj(obj)) {
		m_type = cyborgjson::Object;
	}

	if (cyborgjson::isNull(obj)) {
		return cyborgjson::Error_GenericParsingError;
	} else {
		return cyborgjson::Error_Ok;
	}
}

cyborgjson::JsonValOut unknown::buildJsonObj() {
	cyborgjson::JsonObjOut obj = cyborgjson::read(m_data);
#ifdef CYBORGBEAR_USING_QT
	cyborgjson::JsonValOut val = cyborgjson::objRead(obj, "Value");
#else
	cyborgjson::JsonValOut val = cyborgjson::incref(cyborgjson::objRead(obj, "Value"));
#endif
	cyborgjson::decref(obj);
	return val;
}

bool unknown::loaded() {
	return m_data != "";
}

bool unknown::isBool() {
	return m_type == cyborgjson::Bool;
}

bool unknown::isInt() {
	return m_type == cyborgjson::Integer;
}

bool unknown::isDouble() {
	return m_type == cyborgjson::Double;
}

bool unknown::isString() {
	return m_type == cyborgjson::String;
}

bool unknown::isObject() {
	return m_type == cyborgjson::Object;
}

bool unknown::toBool() {
	cyborgjson::JsonValOut obj = buildJsonObj();
	bool out;
	cyborgjson::readVal(obj, out);
	return out;
}

int unknown::toInt() {
	cyborgjson::JsonValOut obj = buildJsonObj();
	int out;
	cyborgjson::readVal(obj, out);
	return out;
}

double unknown::toDouble() {
	cyborgjson::JsonValOut obj = buildJsonObj();
	double out;
	cyborgjson::readVal(obj, out);
	return out;
}

string unknown::toString() {
	cyborgjson::JsonValOut obj = buildJsonObj();
	string out;
	cyborgjson::readVal(obj, out);
	return out;
}

void unknown::set(Model *v) {
	cyborgjson::JsonObjOut obj = cyborgjson::newJsonObj();
	cyborgjson::JsonValOut val = v->buildJsonObj();
	cyborgjson::objSet(obj, "Value", val);
	m_type = cyborgjson::Object;
	m_data = cyborgjson::write(obj, cyborgjson::Compact);
	cyborgjson::decref(obj);

	unknown *unk = dynamic_cast<unknown*>(v);
	if (unk)
		m_type = unk->m_type;
}

void unknown::set(bool v) {
	cyborgjson::JsonObjOut obj = cyborgjson::newJsonObj();
	cyborgjson::JsonValOut val = cyborgjson::toJsonVal(v);
	cyborgjson::objSet(obj, "Value", val);
	m_type = cyborgjson::Bool;
	m_data = cyborgjson::write(obj, cyborgjson::Compact);
	cyborgjson::decref(obj);
}

void unknown::set(int v) {
	cyborgjson::JsonObjOut obj = cyborgjson::newJsonObj();
	cyborgjson::JsonValOut val = cyborgjson::toJsonVal(v);
	cyborgjson::objSet(obj, "Value", val);
	m_type = cyborgjson::Integer;
	m_data = cyborgjson::write(obj, cyborgjson::Compact);
	cyborgjson::decref(obj);
}

void unknown::set(double v) {
	cyborgjson::JsonObjOut obj = cyborgjson::newJsonObj();
	cyborgjson::JsonValOut val = cyborgjson::toJsonVal(v);
	cyborgjson::objSet(obj, "Value", val);
	m_type = cyborgjson::Double;
	m_data = cyborgjson::write(obj, cyborgjson::Compact);
	cyborgjson::decref(obj);
}

void unknown::set(string v) {
	cyborgjson::JsonObjOut obj = cyborgjson::newJsonObj();
	cyborgjson::JsonValOut val = cyborgjson::toJsonVal(v);
	cyborgjson::objSet(obj, "Value", val);
	m_type = cyborgjson::String;
	m_data = cyborgjson::write(obj, cyborgjson::Compact);
	cyborgjson::decref(obj);
}

bool unknown::operator==(const unknown &o) const {
	return m_type == o.m_type && m_data == o.m_data;
}

bool unknown::operator!=(const unknown &o) const {
	return m_type != o.m_type || m_data != o.m_data;
}


#include "string.h"
#include "Model.hpp"

using namespace models;
using std::stringstream;

Model1::Model1() {
	this->Field1 = "";
	for (int i = 0; i < 4; this->Field3[i++] = 0);
}

cyborgjson::Error Model1::loadJsonObj(cyborgjson::JsonVal in) {
	cyborgjson::Error retval = cyborgjson::Error_Ok;
	cyborgjson::JsonObjOut inObj = cyborgjson::toObj(in);

	{
		cyborgjson::JsonValOut obj0 = cyborgjson::objRead(inObj, "Field1");
		retval |= cyborgjson::readVal(obj0, this->Field1);
	}
	{
		cyborgjson::JsonValOut obj0 = cyborgjson::objRead(inObj, "Field2");
		retval |= cyborgjson::readVal(obj0, this->Field2);
	}
	{
		cyborgjson::JsonValOut obj0 = cyborgjson::objRead(inObj, "Field3");
		retval |= cyborgjson::readVal(obj0, this->Field3);
	}
	{
		cyborgjson::JsonValOut obj0 = cyborgjson::objRead(inObj, "Field4");
		retval |= cyborgjson::readVal(obj0, this->Field4);
	}
	{
		cyborgjson::JsonValOut obj0 = cyborgjson::objRead(inObj, "Field5");
		if (!cyborgjson::isNull(obj0)) {
			if (cyborgjson::isObj(obj0)) {
				cyborgjson::JsonObjOut map0 = cyborgjson::toObj(obj0);
				for (cyborgjson::JsonObjIterator it1 = cyborgjson::jsonObjIterator(map0); !cyborgjson::iteratorAtEnd(it1, map0); it1 = cyborgjson::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgjson::JsonValOut obj1 = cyborgjson::iteratorValue(it1);
					{
						std::string key = cyborgjson::toStdString(cyborgjson::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					retval |= cyborgjson::readVal(obj1, this->Field5[i]);
				}
			}
		}
	}
	return retval;
}

cyborgjson::JsonValOut Model1::buildJsonObj() {
	cyborgjson::JsonObjOut obj = cyborgjson::newJsonObj();
	{
		cyborgjson::JsonValOut out0 = cyborgjson::toJsonVal(this->Field1);
		cyborgjson::objSet(obj, "Field1", out0);
		cyborgjson::decref(out0);
	}
	{
		cyborgjson::JsonValOut obj0 = this->Field2.buildJsonObj();
		cyborgjson::JsonValOut out0 = obj0;
		cyborgjson::objSet(obj, "Field2", out0);
		cyborgjson::decref(out0);
	}
	{
		cyborgjson::JsonArrayOut out1 = cyborgjson::newJsonArray();
		for (cyborgjson::VectorIterator i = 0; i < 4; i++) {
			cyborgjson::JsonValOut out0 = cyborgjson::toJsonVal(this->Field3[i]);
			cyborgjson::arrayAdd(out1, out0);
			cyborgjson::decref(out0);
		}
		cyborgjson::objSet(obj, "Field3", out1);
		cyborgjson::decref(out1);
	}
	{
		cyborgjson::JsonArrayOut out2 = cyborgjson::newJsonArray();
		for (cyborgjson::VectorIterator i = 0; i < this->Field4.size(); i++) {
			cyborgjson::JsonArrayOut out1 = cyborgjson::newJsonArray();
			for (cyborgjson::VectorIterator ii = 0; ii < this->Field4[i].size(); ii++) {
				cyborgjson::JsonValOut out0 = cyborgjson::toJsonVal(this->Field4[i][ii]);
				cyborgjson::arrayAdd(out1, out0);
				cyborgjson::decref(out0);
			}
			cyborgjson::arrayAdd(out2, out1);
			cyborgjson::decref(out1);
		}
		cyborgjson::objSet(obj, "Field4", out2);
		cyborgjson::decref(out2);
	}
	{
		cyborgjson::JsonObjOut out1 = cyborgjson::newJsonObj();
		for (std::map< string, string >::iterator n = this->Field5.begin(); n != this->Field5.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgjson::toStdString(cyborgjson::toString(n->first));
			s >> tmp;
			key = cyborgjson::toString(tmp);
			cyborgjson::JsonValOut out0 = cyborgjson::toJsonVal(this->Field5[n->first]);
			cyborgjson::objSet(out1, key, out0);
			cyborgjson::decref(out0);
		}
		cyborgjson::objSet(obj, "Field5", out1);
		cyborgjson::decref(out1);
	}
	return obj;
}
bool Model1::operator==(const Model1 &o) const {
	if (Field1 != o.Field1) return false;
	if (Field2 != o.Field2) return false;
	if (Field3 != o.Field3) return false;
	if (Field4 != o.Field4) return false;
	if (Field5 != o.Field5) return false;

	return true;
}

bool Model1::operator!=(const Model1 &o) const {
	if (Field1 != o.Field1) return true;
	if (Field2 != o.Field2) return true;
	if (Field3 != o.Field3) return true;
	if (Field4 != o.Field4) return true;
	if (Field5 != o.Field5) return true;

	return false;
}

