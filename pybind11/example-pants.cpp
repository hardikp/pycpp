#include <pybind11/pybind11.h>

int pants(int i) {
  // Return the square
  return i * i;
}

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
  m.doc() = R"pbdoc(
        example module
        -----------------------
        .. currentmodule:: example
        .. autosummary::
           :toctree: _generate
           pants
    )pbdoc";

  m.def("pants", &pants, R"pbdoc(
        Returns the square of a number
    )pbdoc");

  m.attr("__version__") = "dev";
}