#include "all_includes.h"
using namespace std;

int main()
{
	vector<Account*> accounts;

MAIN_MENU:
	{
		int choice = menu();
		if (choice < 1 || choice > 5)
			goto MAIN_MENU;
		else if (choice == 3)
		{
			system("cls");
			cout << "FARE WELLLLL!"
				<< "\n";
			return 0;
		}
		else if (choice == 2)
		{
		ADD_MENU:
			{
				int addChoice = add();
				if (addChoice < 1 || addChoice > 3)
					goto ADD_MENU;
				else if (addChoice == 3)
					goto MAIN_MENU;
				else if (addChoice == 2)
				{
					addWallet(accounts);
					goto MAIN_MENU;
				}
				else
				{
					addCard(accounts);
					goto MAIN_MENU;
				}
			}
		}
		else
		{
		LIST_MENU:
			{
				int listChoice = list(accounts);
				if (listChoice == 0)
					goto MAIN_MENU;
				else if (listChoice < 0 || listChoice > accounts.size())
					goto LIST_MENU;
				else
				{
				ACTION_MENU:
					{
int actionChoice = actions(accounts, listChoice);
			if (actionChoice < 1 || actionChoice > 5)
				goto ACTION_MENU;
			else if (actionChoice == 1)
			{
				replenishment(accounts[listChoice - 1]);
				goto ACTION_MENU;
			}
			else if (actionChoice == 2)
			{
				addExpense(accounts[listChoice - 1]);
				goto ACTION_MENU;
			}
			else if (actionChoice == 3)
			{
			REPORT_MENU:
	{
		int reportChoice = reports();
		if (reportChoice == 1)
		{
			Date date = dayReport();
			ReportGenerator rg;
			map<Date, vector<Expense>> tmp = rg.generateDayReport(date, accounts);
			int ReportAction = reportActions();
			if (ReportAction == 1)
			{
				Report report(tmp);
				report.showDayReport(rg, date, accounts);
				Sleep(5000);
				goto ACTION_MENU;
			}
			else if (ReportAction == 2)
			{
				Report report(tmp);
				report.addToFileDayReport(rg, date, accounts);
			}
			else
			{
				cout << "WROOONG CHOICE"
					<< "\n";
				Sleep(2000);
				goto REPORT_MENU;
			}
		}
		else if (reportChoice == 2)
		{
			Date date = weekReport();
			ReportGenerator rg;
			map<Date, vector<Expense>> tmp = rg.generateWeekReport(date, accounts);
			int ReportAction = reportActions();
			if (ReportAction == 1)
			{
				Report report(tmp);
				report.showDayReport(rg, date, accounts);
				Sleep(5000);
				goto ACTION_MENU;
			}
			else if (ReportAction == 2)
			{
				Report report(tmp);
				report.addToFileWeekReport(rg, date, accounts);
			}
			else
			{
				cout << "WROOONG CHOICE"
					<< "\n";
				Sleep(2000);
				goto REPORT_MENU;
			}
		}
		else if (reportChoice == 3)
		{
			Date date = monthReport();
			ReportGenerator rg;
			map<Date, vector<Expense>> tmp = rg.generateMonthReport(date, accounts);
			int ReportAction = reportActions();
			if (ReportAction == 1)
			{
				Report report(tmp);
				report.showMonthReport(rg, date, accounts);
				Sleep(5000);
				goto ACTION_MENU;
			}
			else if (ReportAction == 2)
			{
				Report report(tmp);
				report.addToFileMonthReport(rg, date, accounts);
			}
			else
			{
				cout << "WROOONG CHOICE"
					<< "\n";
				Sleep(2000);
				goto REPORT_MENU;
			}
		}
		else if (reportChoice == 4)
			goto ACTION_MENU;
		else
			goto REPORT_MENU;
	}
}
		else if (actionChoice == 4)
		{
		RATING_MENU:
		{
		int ratingChoice = ratings();
		if (ratingChoice == 1)
		{
			Date date = weekReport();
			ReportGenerator rg;
			map<Date, vector<Expense>> tmp = rg.generateWeekReport(date, accounts);
			Report report(tmp);
			int whichRating = ByPriceOrByCategory();
			if (whichRating == 1)
				report.showWeekRatingByPrice(rg, date, accounts);
			else if (whichRating == 2)
				report.showWeekRatingByCategory(rg, date, accounts);
			else
				goto RATING_MENU;
		}
		else if (ratingChoice == 2)
		{
			Date date = monthReport();
			ReportGenerator rg;
			map<Date, vector<Expense>> tmp = rg.generateMonthReport(date, accounts);
			Report report(tmp);
			int whichRating = ByPriceOrByCategory();
			if (whichRating == 1)
				report.showMonthRatingByPrice(rg, date, accounts);
			else if (whichRating == 2)
				report.showMonthRatingByCategory(rg, date, accounts);
			else
				goto RATING_MENU;
		}
		else if (ratingChoice == 3)
		{
			Date date = weekReport();
			ReportGenerator rg;
			map<Date, vector<Expense>> tmp = rg.generateWeekReport(date, accounts);
			Report report(tmp);
			int whichRating = ByPriceOrByCategory();
			if (whichRating == 1)
				report.addToFileWeekRatingByPrice(rg, date, accounts);
			else if (whichRating == 2)
				report.addToFileWeekRatingByCategory(rg, date, accounts);
			else
				goto RATING_MENU;
		}
		else if (ratingChoice == 4)
		{
			Date date = monthReport();
			ReportGenerator rg;
			map<Date, vector<Expense>> tmp = rg.generateMonthReport(date, accounts);
			Report report(tmp);
			int whichRating = ByPriceOrByCategory();
			if (whichRating == 1)
				report.addToFileMonthRatingByPrice(rg, date, accounts);
			else if (whichRating == 2)
				report.addToFileMonthRatingByCategory(rg, date, accounts);
			else
				goto RATING_MENU;
		}
	}
}
		else if (actionChoice == 5)
			goto LIST_MENU;
		else
			goto ACTION_MENU;
					}
				}
			}
		}
	}
}