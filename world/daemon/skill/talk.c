inherit SKILL;

int valid_enable(string usage)
{
	return usage=="literate";
}

string perform_action_file(string func)
{
return  "/daemon/class/pfm/talk/" + func;
}
