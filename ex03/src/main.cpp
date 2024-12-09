#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

int main(void)
{
	// ANCHOR - Intern
	MAIN_MSG("Intern")
	{
		try
		{
			Intern alex;
			Bureaucrat bob("bob", 138);
			AForm *tree_paper = alex.makeForm("ShrubberyCreationForm", "home");

			PRINT << tree_paper << ENDL;
			PRINT << bob << ENDL;

			// unsigned
			try
			{
				tree_paper->execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			tree_paper->beSigned(bob);

			// bob grade too low
			try
			{
				tree_paper->execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			bob.incrementGrade();

			// valid
			try
			{
				tree_paper->execute(bob);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
			}

			delete tree_paper;
		}
		CATCH
	}
	SPACER(10)

	return 0;
}
