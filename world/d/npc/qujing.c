//取经

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "乌鸡国",
  "宝象国",
  "天竺国",
  "女儿国",
  "玉华县",
  "金平府",
  "五庄观",
  "祭赛国",
  "钦法国",
  "比丘国",
  "朱紫国",
  "车迟国",
  "江洲国",
  "高老庄",
  });

void create()
{
        seteuid(getuid());
        set("name","");
        remove_call_out("choose_npc");
        call_out("choose_npc",3);      

}

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str;
        object ts,swk,zbj,shs;               

        k = random(sizeof(families));        
        ts = new(__DIR__"ts");
        ts->set("target",families[k]);
        ts->invocation(k);
message("system",HIW"【"+HIR+"西天取经"+HIW+"】"+HIY+"如来佛祖"+NOR"：哈哈! 听说有唐三藏师徒已经来到"+families[k]+"了，相信不久就会到达灵山了。\n"NOR,users());
        reset_eval_cost();
        remove_call_out("choose_npc");
        call_out("choose_npc",18000);
}

