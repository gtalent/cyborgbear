#include <string>
#include <sstream>
#include "Model.hpp"

namespace models2 {

namespace cyborgbear = models::cyborgbear;

}


namespace models2 {

class Model1: public models::Model1 {
};

}

namespace boost {
namespace serialization {

template<class Archive>
void serialize(Archive &ar, models2::Model1 &model, const unsigned int) {
	ar & boost::serialization::base_object<models::Model1>(model);
}

}
}
