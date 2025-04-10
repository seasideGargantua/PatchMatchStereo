#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "PatchMatchStereo.h" // Include your PatchMatchStereo header

namespace py = pybind11;

PYBIND11_MODULE(PatchMatchStereo, m) {
    m.doc() = "Python bindings for PatchMatchStereo";

    // Example: Binding a class from PatchMatchStereo
    py::class_<PatchMatchStereo>(m, "PatchMatchStereo")
        .def(py::init<>()) // Constructor
        .def("Initialize", &PatchMatchStereo::Initialize,
             py::arg("width"), py::arg("height"), py::arg("pms_options"),
             "Initialize the PatchMatchStereo algorithm with image dimensions and options")
        .def("Match", &PatchMatchStereo::Match, 
             py::arg("left_image"), py::arg("right_image"), py::arg("disparity"),
             "Compute the disparity map using PatchMatchStereo")
        .def("GetDisparityMap", &PatchMatchStereo::GetDisparityMap, 
             py::arg("view"),
             "GetDisparityMap using PatchMatchStereo");
}