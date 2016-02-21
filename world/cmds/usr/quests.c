inherit F_CLEAN_UP;

#include <ansi.h>
#include <obstacle.h>
#include "/d/kaifeng/npc/colors.h";

int telling (object me, object who, int short);

string name;

void show_clouds(object me)
{
    mapping colors;
    string *key, msg;
    int i, j;
    if(!me) return;
    
    colors=me->query("quest/colors");
    if(!colors) return;
    i=sizeof(colors);
    if(i<1) return;
    
    key=keys(colors);
    
    if(i==1) {
	msg="慢慢地一小团"+key[0]
	    +"色祥云在$N的身边升起。\n";
    } else {
	j=i;
	msg="$N的身上徐徐飘浮起一小团";
	while(j--) {
	    msg+=key[j];
	}
	if(i==2)
	    msg+="两色祥云。\n";
	else 
	    msg+=chinese_number(i)+"彩祥云。\n";
    }
    
    if(random(10)==0)
	message_vision(msg,me);
    else {
	msg=replace_string(msg,"$N","你");
	tell_object(me,msg);
    }
}

int main(object me, string arg)
{
        object ob;
	int short;

	short=1;
        if( !arg || arg=="-all") {
                ob = me;
                name = "你";
		if(arg=="-all") short=0;
        } else if (wizardp (me)) {
                ob = find_player(arg);
                if(!ob) ob = find_living(arg);
        
                if(!ob) ob = LOGIN_D->find_body(arg);

                if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");
                name = ob->query("name");
		short=0;
        } else return 0;

        telling(me, ob, short);
	
	if(ob==me) 
	    call_out("show_clouds",1,me);

        return 1;
}

int help()
{
        write(@TEXT
指令格式：quests <某人>
          quests
	  quests -all

显示某人解谜的资料。 

请见：help jiemi
TEXT
        );
        return 1;
}

int telling (object me, object who, int short)
{
  mapping mapp;
  if (who->query("quest") == 0)
  {
    write (name+"没有解任何迷。\n");
    return 1;
  }

  write (name+"已经解了"+to_chinese(who->query("quest/number"))+"个迷。\n");
  
  if(!short) {

  write ("    食物："+"解了"+to_chinese(who->query("quest/food/times"))+"次，"+
         "获得"+to_chinese(who->query("quest/food/reward"))+"点品德。\n");
  write ("    送物："+"解了"+to_chinese(who->query("quest/give/times"))+"次，"+
         "获得"+to_chinese(who->query("quest/give/reward"))+"点品德。\n");
  write ("    拜贤："+"解了"+to_chinese(who->query("quest/ask/times"))+"次，"+
         "获得"+to_chinese(who->query("quest/ask/reward"))+"点品德。\n");
  write ("    灭妖："+"解了"+to_chinese(who->query("quest/kill/times"))+"次，"+
         "获得"+to_chinese(who->query("quest/kill/reward"))+"点品德。\n");
  write ("    武器："+"解了"+to_chinese(who->query("quest/weapon/times"))+"次，"+
         "获得"+to_chinese(who->query("quest/weapon/reward"))+"点品德。\n");
  write ("    盔甲："+"解了"+to_chinese(who->query("quest/armor/times"))+"次，"+
         "获得"+to_chinese(who->query("quest/armor/reward"))+"点品德。\n");
  write ("    募捐："+"解了"+to_chinese(who->query("quest/cloth/times"))+"次，"+
         "获得"+to_chinese(who->query("quest/cloth/reward"))+"点品德。\n");
/*
  write ("    首饰："+"解了"+to_chinese(who->query("quest/wearing/times"))+"次，"+
         "获得"+to_chinese(who->query("quest/wearing/reward"))+"点品德。\n");
  write ("    家什："+"解了"+to_chinese(who->query("quest/furniture/times"))+"次，"+
         "获得"+to_chinese(who->query("quest/furniture/reward"))+"点品德。\n");
*/
  write ("\n");
  }

  if(!short) {
  write (name+"共获得：\n");
  write ("    潜能："+to_chinese(who->query("quest/gain/potential"))+"点。\n");
  write ("    道行："+COMBAT_D->chinese_daoxing(who->query("quest/gain/daoxing"))+"道行。\n");
  write ("    技能：\n");
  mapp = who->query("quest/gain/skills");
  if (mapp)
  {
    string *my_keys = keys (mapp);
    int i = sizeof (my_keys);

    while (i--)
    {
       write ("      "+to_chinese(my_keys[i])+to_chinese(mapp[my_keys[i]])
              +"点。\n");
    }
  }
  write ("    属性（临时改善）：\n");
  mapp = who->query("quest/gain/apply");
  if (mapp)
  {
    string *my_keys = keys (mapp);
    int i = sizeof (my_keys);

    while (i--)
    {
       write ("      "+to_chinese(my_keys[i])+to_chinese(mapp[my_keys[i]])
              +"点。\n");
    }
  }
  write ("    银子："+to_chinese(who->query("quest/gain/silver"))+"两。\n");
  write ("\n");
  }

  write (name+"刚刚完成的迷是：\n");
  if (who->query("quest/reason"))
  {
    write ("  “"+who->query("quest/reason")+"……”");
    if (who->query("quest/reward")) {
      if (wizardp(me)) 
        write ("  即将有"+to_chinese(who->query("quest/reward"))+"点奖励。\n");
      else  
        write ("  即将有奖励。\n");
    }  
    else
      write ("\n");
  }    
  write ("\n");

  write (name+"还有如下几个正在解的迷：\n");
  if (mapp = who->query("quest/pending/food"))
  {
    write ("  食物："+mapp["name"]);
    if (wizardp(me))
      write (" 参考系数："+mapp["index"]+"/"+mapp["daoxing"]+"。\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/give"))
  {
    write ("  送物："+mapp["name"] + " " + mapp["objectname"]);
    if (wizardp(me))
      write (" 参考系数："+mapp["index"]+"/"+mapp["daoxing"]+"。\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/ask"))
  {
    write ("  拜贤："+mapp["name"]);
    if (wizardp(me))
      write (" 参考系数："+mapp["index"]+"/"+mapp["daoxing"]+"。\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/kill"))
  {
    write ("  灭妖："+mapp["name"]);
    if (wizardp(me))
      write (" 参考系数："+mapp["index"]+"/"+mapp["daoxing"]+"。\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/weapon"))
  {
    write ("  武器："+mapp["name"]);
    if (wizardp(me))
      write (" 参考系数："+mapp["index"]+"/"+mapp["daoxing"]+"。\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/armor"))
  {
    write ("  盔甲："+mapp["name"]);
    if (wizardp(me))
      write (" 参考系数："+mapp["index"]+"/"+mapp["daoxing"]+"。\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/cloth"))
  {
    write ("  募捐："+mapp["name"]);
    if (wizardp(me))
      write (" 参考系数："+mapp["index"]+"/"+mapp["daoxing"]+"。\n");
    else 
      write ("\n");
  }
/*
  if (mapp = who->query("quest/pending/wearing"))
  {
    write ("  首饰："+mapp["name"]);
    if (wizardp(me))
      write (" 参考系数："+mapp["index"]+"/"+mapp["daoxing"]+"。\n");
    else 
      write ("\n");
  }
  if (mapp = who->query("quest/pending/furniture"))
  {
    write ("  家什："+mapp["name"]);
    if (wizardp(me))
      write (" 参考系数："+mapp["index"]+"/"+mapp["daoxing"]+"。\n");
    else 
      write ("\n");
  }
*/
  write ("\n");

  if (!wizardp(me))
    return 1;
    
  write (name+"解迷暂存使用统计：\n");
  if (mapp = who->query("quest/cache/food"))
  {
    write ("  食物："+to_chinese(sizeof(mapp))+"。\n");
  }
  if (mapp = who->query("quest/cache/give"))
  {
    write ("  送物："+to_chinese(sizeof(mapp))+"。\n");
  }
  if (mapp = who->query("quest/cache/ask"))
  {
    write ("  拜贤："+to_chinese(sizeof(mapp))+"。\n");
  }
  if (mapp = who->query("quest/cache/kill"))
  {
    write ("  灭妖："+to_chinese(sizeof(mapp))+"。\n");
  }
  if (mapp = who->query("quest/cache/weapon"))
  {
    write ("  武器："+to_chinese(sizeof(mapp))+"。\n");
  }
  if (mapp = who->query("quest/cache/armor"))
  {
    write ("  盔甲："+to_chinese(sizeof(mapp))+"。\n");
  }
  if (mapp = who->query("quest/cache/cloth"))
  {
    write ("  募捐："+to_chinese(sizeof(mapp))+"。\n");
  }
/*
  if (mapp = who->query("quest/cache/wearing"))
  {
    write ("  首饰："+to_chinese(sizeof(mapp))+"。\n");
  }
  if (mapp = who->query("quest/cache/furniture"))
  {
    write ("  家什："+to_chinese(sizeof(mapp))+"。\n");
  }
*/
  write ("\n");
  return 1;
}


