#include <boost/function.hpp> 
#include <iostream> 

struct what 
{ 
	what(std::string name):name_(name){}
	std::string name_;
	void hello(std::ostream &os) 
	{ 
		os << "Hello " << name_ << std::endl; 
	} 
	void bye(std::ostream &os)
	{
		os << "Bye " << name_ << std::endl;
	}
}; 

int main() 
{ 
	what world("world");
	what cplusplus("cplusplus");
	//可以匹配what类的成员函数的函数对象
	boost::function<void (what*, std::ostream&)> f = &what::hello; 

	//下面的两个调用方法是一样的，都是world对象的hello方法
	f(&world, boost::ref(std::cout)); 
	world.hello(boost::ref(std::cout));

	//函数对象f被赋了另外一个值
	f = &what::bye; 
	f(&cplusplus, boost::ref(std::cout));
	cplusplus.bye(boost::ref(std::cout));
} 

