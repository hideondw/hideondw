#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME EDUBARDO


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  Dir bfsf(const Pos& p){
    queue<pair<Pos, vector<Dir>>> q;
    pair<Pos, vector<Dir>> mp;
    mp.first = p;
    vector<Dir> v(0);
    mp.second = v;
    mp.second.push_back(Dir(None));
    q.push(mp);
    set<Pos> visited;
    visited.insert(p);
    while(!q.empty()) {
      Pos pv = q.front().first;
      bool Ft = false;
      bool Pt = false;
      Dir dF = None;
      Dir dP = None;
      for(int u = 0; u < 8; ++u) {
        mp.second = q.front().second;
        Pos ps = pv + Dir(u);
        
        set<Pos>::iterator it = visited.find(ps);
        if (it == visited.end()) {
          visited.insert(ps);
          if (pos_ok(ps) and cell(ps).type != Rock) {
            mp.first = ps;
            mp.second.push_back(Dir(u));
            q.push(mp);
            int ide = cell(ps).id;
            if(ide != -1 and unit(ide).player != me()) {
                //Estas aqui, en el caso de encontrar, que hacemos? 
                //
            if(unit(ide).type == Furyan) {
              dF = q.front().second[1];
              Ft = true;
              }
              /*else if (unit(ide).type == Hellhound) {
                int d = q.front().second[1];
                if (d == Dir(Bottom)) return Dir(Top);
                else if (d == Dir(BR)) return Dir(TL);
                else if (d == Dir(Right)) return Dir(Left);
                else if (d == Dir(RT)) return Dir(LB);
                else if (d == Dir(Top)) return Dir(Bottom);
                else if (d == Dir(TL)) return Dir(BR);
                else if (d == Dir(Left)) return Dir(Right);
                else if (d == Dir(LB)) return Dir(RT);
              } */
            else if (unit(ide).type == Pioneer) {
              dP = q.front().second[1];
              Pt = true;
            }
          }
        }      
      }      
    }
      if (Ft) return dF;
      else if (Pt) return dP;
      q.pop();
  }
    return Dir(random(0, 8));
}



  Dir bfsp(const Pos& p){
    queue<pair<Pos, vector<Dir>>> q;
    pair<Pos, vector<Dir>> mp;
    mp.first = p;
    vector<Dir> v(0);
    mp.second = v;
    mp.second.push_back(Dir(None));
    q.push(mp);
    set<Pos> visited;
    visited.insert(p);
    while(!q.empty()) {
      Pos pv = q.front().first;
      bool Mt = false;
      bool Et = false;
      Dir dM = None;
      Dir dE = None;
      for(int u = 0; u < 8; ++u) {
        mp.second = q.front().second;
        Pos ps = pv + Dir(u);
        set<Pos>::iterator it = visited.find(ps);
        if (it == visited.end()) {
          visited.insert(ps);
          if (pos_ok(ps) and cell(ps).type != Rock /*and cell(ps).type != Elevator*/) {
            mp.first = ps;
            mp.second.push_back(Dir(u));
            q.push(mp);
            int ide = cell(ps).id;
            if(ide == -1 and cell(ps).owner != me()) {
              if(cell(ps).owner != -1) {
                Et = true;
                dE = q.front().second[1];
              }
              else {
                Mt = true;
                dM = q.front().second[1];
              }
            }
            else if(ide != -1 and unit(ide).player != me()) {
              //if(unit(ide).type == Pioneer) return q.front().second[1];
              if (unit(ide).type == Hellhound or unit(ide).type == Furyan) {
                int d = q.front().second[1];
                if (d == Dir(Bottom)) {
                  if (Et) return dE;
                  else if (Mt) return dM;
                  else return Dir(Top);
                }
                else if (d == Dir(BR)) {
                  if (Et) return dE;
                  else if (Mt) return dM;
                  else return Dir(TL);
                }
                else if (Dir(u) == Dir(Right)) {
                  if (Et) return dE;
                  else if (Mt) return dM;
                  else return Dir(Left);
                }
                else if (Dir(u) == Dir(RT)) {
                  if (Et) return dE;
                  else if (Mt) return dM;
                  else return Dir(LB);
                }
                else if (Dir(u) == Dir(Top)) {
                  if (Et) return dE;
                  else if (Mt) return dM;
                  else return Dir(Bottom);
                }
                else if (Dir(u) == Dir(TL)) {
                  if (Et) return dE;
                  else if (Mt) return dM;
                  return Dir(BR);
                }
                else if (Dir(u) == Dir(Left)) {
                  if (Et) return dE;
                  else if (Mt) return dM;
                  else return Dir(Right);
                }
                else if (Dir(u) == Dir(LB)) {
                  if (Et) return dE;
                  else if (Mt) return dM;
                  else return Dir(RT);
                }
              }
            }
          }      
        }
      }
      if(Et) return dE;
      if(Mt) return dM;
      q.pop();
    }
    return Dir(random(0, 8));
  }


  /**
   * Types and attributes for your player can be defined here.
   */

  /**
   * Play method, invoked once per each round.
   */
  void move_furyans() {
    vector<int> F = furyans(me());
    int n = F.size();
    for(int i = 0; i < n; ++i) {
      int id = F[i];
      Pos p = unit(id).pos;
      bool Ft = false;
      bool Pt = false;
      Dir dF = None;
      Dir dP = None;
      for(int u = 0; u < 8; ++u) {
        Pos pe = p+Dir(u);
        if(pos_ok(pe) and cell(pe).type != Rock) {
          int ide = cell(pe).id;
          if(ide != -1 and unit(ide).player != me()) {
            if(unit(ide).type == Pioneer) {
              Pt = true;
              dP = Dir(u);
            }
            else if (unit(ide).type == Furyan) {
              Ft = true;
              dF = Dir(u);
            }
            /*else {
              if (Dir(u) == Dir(Bottom)) command(id, Dir(Top)); 
              else if (Dir(u) == Dir(BR)) command(id, Dir(TL));
              else if (Dir(u) == Dir(Right)) command(id, Dir(Left));
              else if (Dir(u) == Dir(RT)) command(id, Dir(LB));
              else if (Dir(u) == Dir(Top)) command(id, Dir(Bottom));
              else if (Dir(u) == Dir(TL)) command(id, Dir(BR));
              else if (Dir(u) == Dir(Left)) command(id, Dir(Right));
              else if (Dir(u) == Dir(LB)) command(id, Dir(RT));
            }*/
          }
        }
      }
      if(Ft) command(id, dF);
      else if (Pt) command(id, dP);
      else command(id, bfsf(p));
    }
  }

  void move_pioneers() {
    vector<int> P = pioneers(me());
    int n = P.size();
    for(int i = 0; i < n; ++i) {
      int id = P[i];
      Pos p = unit(id).pos;
      bool Mt = false;
      bool Et = false;
      Dir dM = None;
      Dir dE = None;
      for(int u = 0; u < 8; ++u) {
        Pos pv = p+Dir(u);
        if(pos_ok(pv) and cell(pv).type != Rock and cell(pv).type != Elevator) {
          int idc = cell(pv).id;
          if (idc == -1 and cell(pv).owner != me()) {
            if(cell(pv).owner != -1) {
                Et = true;
                dE = Dir(u);
              }
              else {
                Mt = true;
                dM = Dir(u);
              }
              
          }
          else if((idc != -1 and unit(id).player != me() and (unit(id).type == Furyan or unit(id).type == Hellhound)) or 
          (idc != -1 and unit(id).player == me() and unit(id).type == Pioneer)) {
            if (Dir(u) == Dir(Bottom)) {
              if (Et) command(id, dE);
              else if (Mt) command(id, dM);
              else command(id, Top);
            }
            else if (Dir(u) == Dir(BR)) {
              if (Et) command(id, dE);
              else if (Mt) command(id, dM);
              else command(id, Dir(TL));
            }
            else if (Dir(u) == Dir(Right)) {
              if (Et) command(id, dE);
              else if (Mt) command(id, dM);
              else command(id, Dir(Left));
            }
            else if (Dir(u) == Dir(RT)) {
              if (Et) command(id, dE);
              else if (Mt) command(id, dM);
              else command(id, Dir(LB));
            }
            else if (Dir(u) == Dir(Top)) {
              if (Et) command(id, dE);
              else if (Mt) command(id, dM);
              else command(id, Dir(Bottom));
            }
            else if (Dir(u) == Dir(TL)) {
              if (Et) command(id, dE);
              else if (Mt) command(id, dM);
              command(id, Dir(BR));
            }
            else if (Dir(u) == Dir(Left)) {
              if (Et) command(id, dE);
              else if (Mt) command(id, dM);
              else command(id, Dir(Right));
            }
            else if (Dir(u) == Dir(LB)) {
              if (Et) command(id, dE);
              else if (Mt) command(id, dM);
              else command(id, Dir(RT));
            }
          }
          else command(id, bfsp(p));
        }
      }
      if (Et) command(id, dE);
      else if(Mt) command(id, dM);
    }
  }

  virtual void play () {
      move_furyans();  
      move_pioneers();
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
