#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  T data;
  int priority;
  Element *next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  ElementPtr<T> Head;
  ElementPtr<T> Tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  Queue<T> newQ;
  newQ.Head=nullptr;
  newQ.Tail=nullptr;
  return newQ;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  ElementPtr<T> pE=new Element<T>;
  pE->data=value;
  pE->priority=priority;
  pE->next=nullptr;

  ElementPtr<T> phelp=q.Head;
  ElementPtr<T> pPrev=nullptr;

  if(q.Head==nullptr&&q.Tail==nullptr){
    q.Head=pE;
    q.Tail=pE;
  }
  else{
    while(pE->priority<=phelp->priority){
      if(phelp->next==nullptr){
        break;
      }
      pPrev=phelp;
      phelp=phelp->next;
    }
    if(phelp==q.Head&&pE->priority>phelp->priority){
      pE->next=phelp;
      q.Head=pE;
    }
    else if(phelp==q.Tail&&pE->priority<phelp->priority){
      phelp->next=pE;
      q.Tail=pE;
    }
    else{
      pPrev->next=pE;
      pE->next=phelp;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  return q.Head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  ElementPtr<T> delE;
  if(q.Head==nullptr&&q.Tail==nullptr){
    delE=nullptr;
  }
  else if(q.Head->next==nullptr){
    delE=q.Head;
    q.Head=nullptr;
    q.Tail=nullptr;
  }
  else{
    delE=q.Head;
    q.Head=q.Head->next;
    delE->next=nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
