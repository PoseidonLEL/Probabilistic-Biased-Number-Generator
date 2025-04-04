import ctypes

# Calling the C++ file and its main function
dll_call = ctypes.WinDLL('./Compilation.dll')
BCF = dll_call.BCF


#Function generates an array of random numbers using the function in the C++ file.
cpdef list BCF_Vector(int minimum, int maximum, int favoredNum, int oStrictness, int length):
    if (oStrictness < 1):
        oStrictness = 1
    elif (oStrictness > 10):
        oStrictness = 10
    if (minimum < 0 or maximum < 0 or minimum > favoredNum or maximum < favoredNum):
        return [-1]*length
    
    cdef list return_array = [0]*length
    cdef int i
    for i in range(length):
        return_array[i] = dll_call._bcf_genvec_pycall(minimum,maximum,favoredNum,oStrictness)
    return return_array


# Cython entry function, not used.
def Biased_Curve_Favoritism():
    return "Use functions BCF() or BCF_Vector()"
