string give_reward(object me) {
  mapping skill=me->query_skills();
  string *skillnames;
  string selected,msg;
  int level, inc=0;

  if (!skill) return "none";

  skillnames=keys(skill);
  selected=skillnames[random(sizeof(skillnames))];

  // mon 3/25/99
  level=skill[selected];
  if(level<80) {
      inc=1;
  } else if(level<160) {
      inc=random(2)==0;
  } else if(level<240) {
      inc=random(4)==0;
  } else {
      inc=random(6)==0;
  }

  if(inc==1) {
    me->set_skill(selected,level+1);
    tell_object(me,"你得到了一级"+ to_chinese(selected) + "。\n");
    return selected;
  }

  return "none";
}
