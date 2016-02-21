//Cracked by Roath

inherit F_CLEAN_UP;
int help(object me);
void create() {seteuid(getuid());}
int main(object me)
{
  if(!me->query("msg_on")) 
  {
     me->set("msg_on",1);
     write("打开留言,ok!\n");
  }
  else 
  { 
     me->delete("msg_on");
     write("关闭留言,ok!\n");
  }
  return 1;
 }
 int help(object me)
{
    write(@HELP
指令格式：pager
这个指令可以让你打开或者关闭预先设置好的留言。
相关指令 : set reply_msg
HELP
    );
    return 1;
}

  