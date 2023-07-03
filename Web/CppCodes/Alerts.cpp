#include "Errors/AllErrors.hpp"
using namespace std;
Error::Error(string errorText_) { errorText = errorText_; }
string Error::getText() const { return errorText; }
void Error::printErrors() const { cerr << errorText << endl; }

BadRequest::BadRequest() { errorText = "Bad Request"; }

NotFound::NotFound() { errorText = "Not Found"; }

Empty::Empty() { errorText = "Empty"; }

PermissionDenied::PermissionDenied() { errorText = "Permission Denied"; }

Message::Message(string text_) { text = text_; }
void Message::printMessage() const { cout << text; }