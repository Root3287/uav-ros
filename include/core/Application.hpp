#pragma once
class Application{
	protected:
		int _argc;
		char** _argv;
	public:
		Application(){};
		Application(int& argc, char**& argv) : _argc(argc), _argv(argv){};
		virtual void run();
		virtual void init()=0;
		virtual void update(float delta) =0;
		virtual ~Application() = default;
};
