#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

int found;

int search_dir(string *dirs, string arg, object me, int wildcard, int wizp);
int find_sub(mixed *filename);
string replace_color(string msg,int flag);
int main(object me, string arg)
{
	int i;
	string newarg,str1,str2,file, *search;
        string *default_search;
	int wildcard;

	// If no topic specified, give the topics.
	if( !arg ) {
		cat(HELP_DIR + "help/topics");
		return 1;
	}

	// Else, try if a command name is specified.
	seteuid(getuid());
	if( stringp(file = me->find_command(arg)) ) {
		notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
		return file->help(me);
	}
	//Now see if it aliases to a command.
	//mon 10/27/97
	if( stringp(file =
	  me->find_command(ALIAS_D->process_global_alias(arg))) ) {
		notify_fail("有这个指令存在，但是并没有详细的说明文件。\n");
		return file->help(me);
	}
        
	// Search the individual search path first.
	if( pointerp(search = me->query("help_search_path")) ) {
		i = sizeof(search);
		while(i--) if( file_size(search[i] + arg)>0 ) {
			me->start_more( replace_color(read_file(search[i] + arg),1) );
			return 1;
		}
	}

	// Support efun/lfun help with same name as other topics such as
	// ed() and ed command.
	// Using a "()" after the function name can prevent it being
	// interpreted as a user command with the same name. -- mon
	sscanf(arg, "%s()", arg);
	arg=replace_string(arg, "/", "");

        if(strsrch(arg,"*")>=0 || strsrch(arg,"?")>=0) wildcard=1;
	else wildcard=0;

	found=0;
	write("\n");

	// Finally, search the default search paths.
	// by snowcat feb 21 1998
	if (wizardp(me))
		default_search = DEFAULT_SEARCH_PATHS;
	else
		default_search = DEFAULT_PLAYER_SEARCH_PATHS;
	if( pointerp(default_search) ) {
	  if(search_dir(default_search, arg, me, wildcard, wizardp(me))>0) {
	    if(wildcard) write("找到"+chinese_number(found)+
	      "个相关主题。\n");
	    return 1;
          }
	}

	return notify_fail("没有针对这项主题的说明文件。\n");
}

// recursively search the help dir.
// mon 2/26/98
int search_dir(string *dirs, string arg, object me, int wildcard, int wizp)
{
    int i = sizeof(dirs), j;
    mixed *filenames, *sub_dir;

    while(i--) {
      filenames=get_dir(dirs[i] + arg, -1);

      if(pointerp(filenames) && sizeof(filenames)) {
        if(!wildcard && filenames[0][1]>0) {
	//without wildcard, filenames[0] must be the only match.
	//which should be the same as "dirs[i] + arg"
	  me->start_more( read_file(dirs[i] + arg) );
	  return 1;
        }

	if(wildcard) {
          j=sizeof(filenames);
	  while(j--) {
            if(filenames[j][1]>0) {
	      write("help "+filenames[j][0]+
	        (wizp?"     ("+dirs[i]+")":"")+ "\n");
	      found++;
            }
	  }
	}
      }

      //check sub_directories
      if(pointerp(filenames=get_dir(dirs[i], -1))) {
        if(pointerp(sub_dir=filter_array(filenames, "find_sub"))) {
	  string *dirs1=({});

          j=sizeof(sub_dir);
	  while(j--) {
	    dirs1+=({dirs[i]+sub_dir[j][0]+"/"}); 
	  }

	  if(search_dir(dirs1, arg, me, wildcard, wizp)==1 
	    && !wildcard) return 1;
        }
      }
    }

    return (wildcard*found);
}

int find_sub(mixed *filename)
{
    return (filename[1]==-2);
}

int help(object me)
{
	write(@HELP
指令格式：help <主题>              例如： help cmds
          help <函数名称>()        例如： help call_out()

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。

除了有关指令名(command)的说明以外，在主题名称中 Help 支持 wildcards 
如 '?' 和 '*'，例如： help map-m*。

HELP
	);
	return 1;
}


string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}