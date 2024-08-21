#pragma once
#include <map>
#include "ASpell.hpp"

class SpellBook
{
	private :
		SpellBook & operator=(SpellBook const & rhs);
		SpellBook(SpellBook const & obj);
		std::map < std::string, ASpell * > _SpellBook;
	
	public :
		SpellBook();
		~SpellBook();
		void learnSpell(ASpell *);
		void forgetSpell(std::string const &);
		ASpell * createSpell(std::string const &);
};

