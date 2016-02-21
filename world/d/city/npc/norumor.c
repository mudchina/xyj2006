void relay_channel(object ob, string channel, string msg) {
        string who;
        if( !userp(ob) || (channel != "rumor") ) return;
      if (wizardp(ob)) return;
        who = ob->query("name");
        if( ob==this_object() ) return;
        message_vision(who+" says:"+msg+"\n");
        if (!random(4)) {
          remove_call_out("reveal");
          call_out("reveal",1,ob);
        }
}
void reveal(object who) {
  string name=who->query("name"),id=who->query("id");
  switch (random(5)) {
   case 0: command("rumor* 某人恶狠狠地威胁道："+name+"，你个"+RANK_D->query_rude(who)+"！给我闭嘴！");break;
    case 1: command("rumor* 某人向"+name+"摇摇食指，「小朋友，这样不可以喔！」");break;  
     case 2: command("say "+name+"这"+RANK_D->query_rude(who)+"又在造谣了。");break;
     case 3: command("say "+name+"怎么那么喜欢造谣呀。");break;
     case 4: command("rumor* 某人客客气气地对"+name+"道：是不是你在造谣？如果是的话请你别再折腾了。");break;
  }
}
