#ifndef _MemberOperators_HPP_
#define _MemberOperators_HPP_
bool operator==(int type_, std::shared_ptr<Member> member);
bool operator==(std::shared_ptr<Member> member, int type_);
bool operator==(std::string username_, const Member &member);
bool operator==(std::string username_, std::shared_ptr<Member> member);
bool operator==(std::shared_ptr<Member> member, std::string username_);
#endif