#include"common.hpp"
#include <iostream>
#include <fstream>
#include"HTTPRequest.hpp"
#pragma comment(lib,"ws2_32.lib")
namespace big::auth
{
	bool login()
	{
		//Get
		try
		{
			http::Request request{ "http://test.com/test" };

			const auto response = request.send("GET");
			std::cout << std::string{ response.body.begin(), response.body.end() } << '\n';
		}
		catch (const std::exception& e)
		{
			std::cerr << "Request failed, error: " << e.what() << '\n';
		}

		//Post
		try
		{
			http::Request request{ "http://test.com/test" };
			const std::string body = "foo=1&bar=baz";
			const auto response = request.send("POST", body, {
				"Content-Type: application/x-www-form-urlencoded"
				});
			std::cout << std::string{ response.body.begin(), response.body.end() } << '\n';
		}
		catch (const std::exception& e)
		{
			std::cerr << "Request failed, error: " << e.what() << '\n';
		}
		return false;
	}
}