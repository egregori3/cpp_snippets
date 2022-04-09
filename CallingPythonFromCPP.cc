#include <iostream>
#include <string>

using namespace std;

// https://docs.python.org/3/extending/embedding.html
void CallPython(string PythonModuleName, string PythonFunctionName)
{
	char *funcname = new char[PythonFunctionName.length() + 1];
	std::strcpy(funcname, PythonFunctionName.c_str());

	char *modname = new char[PythonModuleName.length() + 1];
	std::strcpy(modname, PythonModuleName.c_str());

	// Initialize the Python interpreter 
	// https://docs.python.org/3/c-api/init.html#c.Py_Initialize
	Py_Initialize(); 

	// Import a module. This is best described by referring to the built-in Python function __import__().
	// https://docs.python.org/3/c-api/import.html?highlight=pyimport_importmodule#c.PyImport_ImportModule 
	printf("Loading the Python module %s\n", modname);
	PyObject* my_module = PyImport_ImportModule(modname);

	// Print a standard traceback to sys.stderr and clear the error indicator
	// https://docs.python.org/3/c-api/exceptions.html?highlight=pyerr_print#c.PyErr_Print
	PyErr_Print();	

	// Get the address of the particular Python function in the imported module
	// https://docs.python.org/3/c-api/object.html?highlight=pyobject_getattrstring#c.PyObject_GetAttrString
	printf("Getting address of %s in Python module\n", funcname);
	PyObject* my_function = PyObject_GetAttrString(my_module, funcname);

	// Call a callable Python object callable, with arguments given by the tuple args. 
	// If no arguments are needed, then args can be NULL.
	// https://docs.python.org/3/c-api/call.html?highlight=pyobject_callobject#c.PyObject_CallObject
	PyObject* my_result = PyObject_CallObject(my_function, NULL);

	// Undo all initializations made by Py_Initialize() and subsequent use of Python/C API functions, 
	// and destroy all sub-interpreters (see Py_NewInterpreter() below) that were created and not yet 
	// destroyed since the last call to Py_Initialize(). Ideally, this frees all memory allocated by the Python interpreter.
	// https://docs.python.org/3/c-api/init.html?highlight=py_finalize#c.Py_FinalizeEx
	Py_Finalize();

	delete[] procname;
	delete[] modname;
}
