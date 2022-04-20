#pragma once
#include "Text.h"
using namespace System;
namespace MyDLL {
	public ref class Csh_text {
		C_Text * obj;
	public:
		Csh_text(String^ s) {
			std::string res = " ";
			for (int i = 0; i < s->Length; i++) {
				res += s[i];
			}
			obj = new C_Text(res);
		}
	};
}