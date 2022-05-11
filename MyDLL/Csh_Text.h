#pragma once
#include "Text.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
namespace MyDLL {
	public ref class Csh_text {
		C_Text * obj;
	public:
		Csh_text(String^ s) {
			std::string res =msclr::interop::marshal_as<std::string>(s);
			obj = new C_Text(res);
		}
		String^ getHead() {
			String^ s = gcnew String(obj->getHead().c_str());
			return s;
		}
		void setHead(String^ s) {
			std::string res = msclr::interop::marshal_as<std::string>(s);
			obj->setHead(res);
		}
		void CreateSection(String^ s) {
			std::string res = msclr::interop::marshal_as<std::string>(s);
			obj->CreateSection(res);
		}
		String^ String_Sections() {
			std::string res=obj->String_Sections();
			String^ s = gcnew String(res.c_str());
			return s;
		}


	};
}