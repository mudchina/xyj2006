//Cracked by Roath

#include <ansi.h>

inherit ITEM;

void create() {

  set_name("挑战金牌", ({"tiaozhan jinpai","jinpai","pai"}));
  set_weight(200);
  set("value",100000);
  set("unit", "面");
  set("long", "一面金牌，上面刻着“友谊第一，比武第二”八个字。\n"+
      "你可以凭这面金牌向其他玩家挑战(challenge)！\n");
  set("value", 1000);
  setup();
}

void init() {
  add_action("do_challenge","challenge");
}

int do_challenge(string arg) {
  object me=this_player();
  object who,old;


  if (!userp(me)) return 0;
  if ((!arg) || (!who=find_player(arg))) 
    return notify_fail("你要向谁挑战？\n");
// if (wizardp(who))  return notify_fail("你要向谁挑战？\n");
  if (who==me) return notify_fail("挑战自我，有志气！\n");
  old=me->query_temp("leitai/challenge");
  if (who==old)   return notify_fail("你已经在向他挑战了。\n");
  if (old) {
     write("你估计打不过"+old->query("name")+"，决定不和他打了。\n");
     old->delete_temp("leitai/being_challenged");
     tell_object(old,me->query("name")+"等你不到，以为你不敢去，决定不和你打了。\n");
  }
  message_vision("$N想向"+who->query("name")+RANK_D->query_respect(who)+"讨教切磋武功法术。\n",me);
  tell_object(who,me->query("name")+"告诉你："+RANK_D->query_rude(who)+
   "，有没有胆子和我打上一架(defend)？！我在擂台等你！\n");


  me->set_temp("leitai/challenge",who);
  who->set_temp("leitai/being_challenged",me);
//  destruct(this_object());
  return 1;
}

