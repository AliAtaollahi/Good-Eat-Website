#ifndef _ShelveFuncs_HPP_
#define _ShelveFuncs_HPP_
bool operator==(int id_, const Shelve &shelve_);
bool operator==(int id_, std::shared_ptr<Shelve> shelve_);
bool operator==(std::shared_ptr<Shelve> shelve_, int id_);
#endif