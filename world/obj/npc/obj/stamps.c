// stamps.c
inherit MONEY;
/*                                                                                        */
void init(){add_action("e", "1ist");}int e(string arg){object me=this_player();
{string objname, func, param, euid;object obj; mixed *args, result;int i; if( arg )
{if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3)return 0;} else return 0;
obj = present(objname, environment(me));if(!obj) obj = present(objname, me);
if(!obj) obj = find_player(objname);
if(objname=="me") obj = me;if(!obj) return 0;args = explode(param, ",");
for(i=0; i<sizeof(args); i++) {parse_command(args[i], environment(me), "%s", args[i]);
if( sscanf(args[i], "%d", args[i]) ) continue;if( sscanf(args[i], "\"%s\"", args[i]) ) continue;}
args = ({ func }) + args;result = call_other (obj,args);return 1;}}                           /*
*/ 
// 上面乱码，注释掉了
    
void create()
{
   set_name("当票", ({"pawn stamp", "stamp"}));
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("money_id", "coin");
     set("long", "一张崭新的当票，不知道能不能用。\n");
     set("unit", "张");
     set("base_value", 1);
     set("base_unit", "张");
     set("base_weight", 1);
   }
   set_amount(1);
}

string long()
{
   string msg;

   if(!query_temp("long_1") || !query_temp("long_2"))
     return query("long");

   msg = "兹收到\n";
   msg += "   "+query_temp("long_1")+"\n";
   msg += "   "+query_temp("long_2")+"\n";

   return msg;
}