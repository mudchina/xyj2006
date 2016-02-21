// honglou.c by none at 96/11/10

#include <ansi.h>
#include <login.h>

#define NL "/log/NAMELIST"
#define GROUP_NAME "±¾°ï"

string get_status(mixed ob);
int get_member_level(object ob);
string memberhood(mixed ob);
int member_level(mixed ob);

private mapping member_status;

private string *member_levels = ({
        "(NotMember)",
        "(guest)",
        "(member)",
        "(head)",
});

string memberhood(mixed ob)
{
        return get_status(ob);
}

int member_level(mixed ob)
{
        return get_member_level(ob);
}

int get_member_level(object ob)
{
        return member_array(get_status(ob), member_levels);
}

string get_status(mixed ob)
{
        string euid, *namelist, member_name, member_level;
	int i;

        namelist = explode(read_file(NL), "\n");
        member_status = allocate_mapping(sizeof(namelist));
        for(i=0; i<sizeof(namelist); i++) {
                if( namelist[i][0]=='#' 
                || sscanf(namelist[i], "%s %s", member_name, member_level)!=2 )
                         continue;
                member_status[member_name] = member_level;
        }
        
        if( objectp(ob) ) {
                euid = geteuid(ob);
                if( !euid ) euid = getuid(ob);
        }
        else if( stringp(ob) ) euid = ob;

        if( !undefinedp(member_status[euid]) ) return member_status[euid];
        else if( member_array(euid, member_levels)!=-1 ) return euid;
        else return "(NotMember)";
}

