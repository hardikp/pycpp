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
           add
    )pbdoc";

  m.def("add", &add, R"pbdoc(
        Add two numbers
        Some other explanation about the add function.
    )pbdoc");

  m.attr("__version__") = "dev";
}