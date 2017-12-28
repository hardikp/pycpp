#include <pybind11/pybind11.h>

struct Classy {
  Classy() : number(1) {}

  int miami() {
    if (number > 1)
      number /= 2;
    return number;
  }

  int new_york() {
    if (number < 1024 * 1024)
      number *= 2;
    return number;
  }

  int number;
};

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
  py::class_<Classy>(m, "Classy")
      .def(py::init())
      .def("miami", &Classy::miami)
      .def("new_york", &Classy::new_york);
}