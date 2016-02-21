// by canoe
#include <ansi.h>
inherit F_CLEAN_UP;
void create() { seteuid( getuid() ); }
int main(object me, string arg)
{
   object ob;
   if( me != this_player(1) ) return 0;
   ob = me->query_temp("link_ob");
   if( !ob ) 
   	return notify_fail("你不是由正常途径进入的，不能修改管理密码！\n");
   while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
   write(HIG"\n注意：人物口令修改、档案备份、自杀等需要管理密码；\n\n"NOR);
   write(HIR"      一般情况下不予更改，请务必妥善保存。\n\n"NOR);
	
   if(ob->query("super_password"))
   {
   write("为了安全起见，请先输入您原来的管理密码：");
   input_to("get_old_pass", 1, ob);
   }
   else
   {
   write("您还没有设定管理密码，请您现在设定：");
   input_to("get_new_pass",1,ob);
   }   
   return 1;
}

private void get_old_pass(string pass, object ob)
{
   string old_pass;
   write("\n");
   old_pass = ob->query("super_password");
   if( crypt(pass, old_pass)!=old_pass ) {
     write("管理密码错误！\n");
     MONITOR_D->report_system_object_msg(ob,"修改管理密码错误！");
     return;
   }
   write("请输入新的管理密码：");
   input_to("get_new_pass", 1, ob );
}

private void get_new_pass(string pass, object ob)
{
   write("\n");
        if( strlen(pass)<7 ) {
                write("管理密码至少要由七个字符组成，请重设您的管理密码：");
                input_to("get_new_pass", 1, ob);
                return;
        }
   write("\n请再输入一次新的管理密码：");
   input_to("confirm_new_pass", 1, ob, crypt(pass,0));
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
   write("\n");
   if( crypt(pass, new_pass)!=new_pass ) {
     write("对不起，您输入的管理密码并不相同，继续使用原来的管理密码。\n");
     return;
   }
   seteuid(getuid());
   if( !ob->set("super_password", new_pass) ) {
     write("管理密码变更失败！\n");
     return;
   }

   ob->save();
   write("管理密码变更成功。\n");
}

int help(object me)
{
   write(@HELP
指令格式 : passwd
 
这个指令可以修改你的人物管理密码。
 
HELP
    );
    return 1;
}
