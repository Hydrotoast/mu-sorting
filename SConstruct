mode = ARGUMENTS.get('mode', 'debug')
mode_flag = '-DNDEBUG' if mode == 'release' else ''

if mode not in ['debug', 'release']:
	print "Error: expected 'debug' or 'release', found: %s" % mode
	Exit(1)

print '**** Compiling in %s mode...' % mode

includes = [
	'/usr/local/include/unittest', 
	'/usr/local/include/benchmark',
	'/usr/local/include/debug'],

env = Environment(CPPPATH=includes,
				  CXXFLAGS=['-std=c++11', '-O3', mode_flag])
env.Replace(CXX='clang++')

SConscript('sorting/SConscript', variant_dir='build', duplicate=False, exports=['env'])
