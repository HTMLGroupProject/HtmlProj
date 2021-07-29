#include "intoTag.h"

string intoTag(char userChoice, string content, string desc) {
	switch (userChoice)
	{
	case 'T'://to add a title tag
		return "<title>" + content + "</title>";
		break;
	case 'S'://For making text bold
		return "<strong>" + content + "</strong>";
		break;
	case 'P'://Adding the paragraph tag
		return "<p>" + content + "</p>";
		break;
	case 'X'://Creating a link with optional desciption tag
		return "<a href=" + content + ">" + desc + "</a>";
		break;
	case 'C'://Allow user to add comments to the html file
		return "<!--" + content + "-->";
		break;
	case 'H'://Header with optional desc tag to change header size
		return "<h" + desc + ">" + content + "</h" + desc + ">";
		break;
	case 'I'://For allowing user to add images to the html page
		return "<a href=" + content + ">" + desc + "</a>";
		break;
	case 'E'://Emphasises text
		return "<em>" + content + "</em>";
		break;
	case 'D'://Allows users to make a div
		return "<div class=" + content + ">" + desc + "</div>";
		break;
	case 'R'://For allowing to make a horizontal break
		return "<hr>";
		break;
	default:
		return "";
		break;
	}
}
