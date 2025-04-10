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

    py::class_<PMSOption>(m, "PMSOption")
        .def(py::init<>())
        .def_readwrite("patch_size", &PMSOption::patch_size)
        .def_readwrite("min_disparity", &PMSOption::min_disparity)
        .def_readwrite("max_disparity", &PMSOption::max_disparity)
        .def_readwrite("gamma", &PMSOption::gamma)
        .def_readwrite("alpha", &PMSOption::alpha)
        .def_readwrite("tau_col", &PMSOption::tau_col)
        .def_readwrite("tau_grad", &PMSOption::tau_grad)
        .def_readwrite("num_iters", &PMSOption::num_iters)
        .def_readwrite("is_check_lr", &PMSOption::is_check_lr)
        .def_readwrite("lrcheck_thres", &PMSOption::lrcheck_thres)
        .def_readwrite("is_fill_holes", &PMSOption::is_fill_holes)
        .def_readwrite("is_fource_fpw", &PMSOption::is_fource_fpw)
        .def_readwrite("is_integer_disp", &PMSOption::is_integer_disp);
    // Add more bindings as needed
}