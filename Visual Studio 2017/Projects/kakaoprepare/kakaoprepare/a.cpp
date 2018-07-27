// basic-http-client.cpp
#include <http_client.h>
#include <filestream.h>
#include <iostream>
#include <sstream>

using namespace web::http;
using namespace web::http::client;

// Creates an HTTP request and prints the length of the response stream.
pplx::task<void> HTTPStreamingAsync()
{
	http_client client(L"http://www.fourthcoffee.com");

	// Make the request and asynchronously process the response.
	return client.request(methods::GET).then([](http_response response)
	{
		// Print the status code.
		std::wostringstream ss;
		ss << L"Server returned returned status code " << response.status_code() << L'.' << std::endl;
		std::wcout << ss.str();

		// TODO: Perform actions here reading from the response stream.
		auto bodyStream = response.body();

		// In this example, we print the length of the response to the console.
		ss.str(std::wstring());
		ss << L"Content length is " << response.headers().content_length() << L" bytes." << std::endl;
		std::wcout << ss.str();
	});

	/* Sample output:
	Server returned returned status code 200.
	Content length is 63803 bytes.
	*/
}

// Builds an HTTP request that uses custom header values.
pplx::task<void> HTTPRequestCustomHeadersAsync()
{
	http_client client(L"http://www.fourthcoffee.com");

	// Manually build up an HTTP request with header and request URI.
	http_request request(methods::GET);
	request.headers().add(L"MyHeaderField", L"MyHeaderValue");
	request.set_request_uri(L"requestpath");
	return client.request(request).then([](http_response response)
	{
		// Print the status code.
		std::wostringstream ss;
		ss << L"Server returned returned status code " << response.status_code() << L"." << std::endl;
		std::wcout << ss.str();
	});

	/* Sample output:
	Server returned returned status code 200.
	*/
}

// Upload a file to an HTTP server.
pplx::task<void> UploadFileToHttpServerAsync()
{
	using concurrency::streams::file_stream;
	using concurrency::streams::basic_istream;

	// To run this example, you must have a file named myfile.txt in the current folder.
	// Alternatively, you can use the following code to create a stream from a text string.
	// std::string s("abcdefg");
	// auto ss = concurrency::streams::stringstream::open_istream(s);

	// Open stream to file.
	return file_stream<unsigned char>::open_istream(L"myfile.txt").then([](pplx::task<basic_istream<unsigned char>> previousTask)
	{
		try
		{
			auto fileStream = previousTask.get();

			// Make HTTP request with the file stream as the body.
			http_client client(L"http://www.fourthcoffee.com");
			return client.request(methods::PUT, L"myfile", fileStream).then([fileStream](pplx::task<http_response> previousTask)
			{
				fileStream.close();

				std::wostringstream ss;
				try
				{
					auto response = previousTask.get();
					ss << L"Server returned returned status code " << response.status_code() << L"." << std::endl;
				}
				catch (const http_exception& e)
				{
					ss << e.what() << std::endl;
				}
				std::wcout << ss.str();
			});
		}
		catch (const std::system_error& e)
		{
			std::wostringstream ss;
			ss << e.what() << std::endl;
			std::wcout << ss.str();

			// Return an empty task.
			return pplx::task_from_result();
		}
	});

	/* Sample output:
	The request must be resent
	*/
}

int wmain()
{
	// This example uses the task::wait method to ensure that async operations complete before the app exits. 
	// In most apps, you typically don�t wait for async operations to complete.

	std::wcout << L"Calling HTTPStreamingAsync..." << std::endl;
	HTTPStreamingAsync().wait();

	std::wcout << L"Calling HTTPRequestCustomHeadersAsync..." << std::endl;
	HTTPRequestCustomHeadersAsync().wait();

	std::wcout << L"Calling UploadFileToHttpServerAsync..." << std::endl;
	UploadFileToHttpServerAsync().wait();
}

