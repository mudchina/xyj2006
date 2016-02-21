//Cracked by Roath

inherit F_SAVE;
inherit ROOM;

// string query_save_file() { return "/u/xlb/score";}
object keeper;
object findkeeper() {
  object kantai;

  if (keeper) return keeper;
  kantai=load_object(__DIR__"kantai");
  keeper=present("chang jian",kantai);
  if (!keeper) {
      keeper=new(__DIR__"scorekeeper");
      keeper->move(kantai);
  }
  return keeper;
}

int writetokeeper() {
  findkeeper()->set("scores",query("scores"));
  findkeeper()->set("ranks",query("ranks"));
  findkeeper()->set("list",query("list"));
  return findkeeper()->save();
}

void restore() {
  set("scores",findkeeper()->query("scores"));   
  set("ranks",findkeeper()->query("ranks"));   
  set("list",findkeeper()->query("list"));   
}

void update_winner_rank(object);
void update_loser_rank(object);

int update_score(object winner,object loser){
  int bonus,old_bonus,loss;

  if (!winner || !loser) return 0;
  if (wizardp(winner) || wizardp(loser)) return 1;

  bonus=(loser->query("combat_exp")+loser->query("daoxing"))/10000+1;
  old_bonus=winner->query("leitai_score/"+loser->query("id")+"/bonus");
  if (bonus>old_bonus) {
    winner->set("leitai_score/"+loser->query("id")+"/bonus",bonus);
    winner->add("leitai_score/total",bonus-old_bonus);
    winner->set("leitai_score/"+loser->query("id")+"/time",time());
    message_vision("$N的等级分增加了"+(bonus-old_bonus)+"点！\n",winner);
    update_winner_rank(winner);
    winner->save();
  }
  if (loss=(int)loser->query("leitai_score/"+winner->query("id")+"/bonus")) {
     loser->delete("leitai_score/"+winner->query("id"));
     loser->add("leitai_score/total",-loss);
     message_vision("$N的等级分减少了"+loss+"点！\n",loser);
     update_loser_rank(loser);
     loser->save();
  }
  return writetokeeper();
}

void report(object who) {
  string id;
  int score,rank;

  if (!who) return;
  id=who->query("id");

  score=query("scores/"+id);  
  rank=query("ranks/"+id);

  write("你现有等级分"+score+"分，");
  if (rank) write("排名第"+chinese_number(rank)+"。\n");
    else write("排行榜上还没有名次。\n");
}

void update_winner_rank(object who) {
  string id;
  int next,size,score,old_rank,next_score=0;

  if (!who) return;
  id=who->query("id");
  score=who->query("leitai_score/total");
  set("scores/"+id,score);
  if (!old_rank=query("ranks/"+id)) {
    add("size",1);
    old_rank=query("size");
    set("list/"+old_rank,id);
    set("ranks/"+id,old_rank);
  }
  if (old_rank<=1) return;  
  next=query("list/"+(old_rank-1));
  next_score=query("scores/"+next);
  while (old_rank!=1 && score>next_score) {
     set("list/"+old_rank,next);
     add("ranks/"+next,1);
     set("list/"+(old_rank-1),id);
     add("ranks/"+id,-1);

     old_rank--;
     next=query("list/"+(old_rank-1));
     next_score=query("scores/"+next);
  }   
}

void update_loser_rank(object who) {
  string id;
  int next,size,score,old_rank,next_score=0;

  if (!who) return;
  id=who->query("id");
  score=who->query("leitai_score/total");
  set("scores/"+id,score);
  old_rank=query("ranks/"+id);
  size=query("size");
  if (old_rank==size) return;  
  next=query("list/"+(old_rank+1));
  next_score=query("scores/"+next);
  while (old_rank!=size && score<next_score) {
     set("list/"+old_rank,next);
     add("ranks/"+next,-1);
     set("list/"+(old_rank+1),id);
     add("ranks/"+id,1);

     old_rank++;
     next=query("list/"+(old_rank+1));
     next_score=query("scores/"+next);
  }   
}

