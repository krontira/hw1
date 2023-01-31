#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{

	/*if(tail_->last != ARRSIZE) {//checks if node at the end is full, if not adds to val
		tail_->val[tail_->last++] = val;
		




	}
	else if(head_ == NULL){ //checks if there are any initiated nodes, otherwise creates one and adds to firt index
		head_ = new Item;
		tail_ = head_;
		head_->val[0] = val;
		//tail_ = head_;
		head_->last = head_->last+1;
		
	}


	else{//(tail_->last == ARRSIZE){ //checks if the array at the current tail nose is full
		Item* tailprev = tail_; //temp to point to location
		tail_->next = new Item;
		tail_ = tail_->next;
		tail_->prev = tailprev;
		tail_->val[0] = val;
		
		
		tail_->last +=1;


		

		
	
	}
	size_+=1;*/
	
	if(head_ == NULL){ //checks if head node exists
		head_ = new Item;
		tail_ = head_;
		head_->val[0] = val;
		head_->last+=1;
	}



	else if(ARRSIZE != tail_->last){ //last node has space in array 
		tail_->val[tail_->last] = val;
		tail_->last+=1;

	}

	
	
	else{
		Item* tailtemp = tail_;
		tail_->next = new Item;
		tail_ = tail_->next;
		//tail_->prev = tailtemp;
		tail_->val[0] = val;
		tail_->last+=1;
		tail_->prev = tailtemp;
	}
	size_ +=1;
	
}

void ULListStr::push_front(const std::string& val)
{
	if(head_ == NULL){
		Item* newitem = new Item;
		
		tail_ = newitem;
		head_ = newitem;
		//newitem->next = NULL;
		//newitem->prev = NULL;
		
		newitem->last = 1;
		//newitem->first = 0;
		newitem->val[0] = val;

	}

	else if(head_->first != 0 && head_!=NULL){
		head_->val[(head_->first)-1] = val;
		head_->first = (head_->first)-1;
	}

	else if(head_->first == 0 && head_ != NULL ){
		Item* newitem = new Item;
		newitem->next = head_;
		newitem->prev = NULL;
		head_->prev = newitem;
		
		head_ = newitem;
		newitem->val[ARRSIZE-1] = val;
		newitem->first = ARRSIZE-1;
		newitem->last = ARRSIZE;
		




	}

	size_++;


}

void ULListStr::pop_front()
{
	if((head_->last - head_->first )>1){
		(head_->first) = (head_->first) + 1;
	}

	else if((head_->last - head_->first)==1 && (head_ == tail_)){//checks if the node has one elementin the aray
		Item* tempdel = head_;
		tail_ = NULL;
		head_ = NULL;
		delete tempdel;

	}

	else if((tail_ != head_) && ((head_->last - head_->first) == 1)){
		Item* deltemp = head_;
		head_ = deltemp->next;
		head_->prev = NULL;
		
		delete deltemp;

	}
	size_ = size_-1;
}

void ULListStr::pop_back()
{
	if((tail_->last - tail_->first)==1){
		if(head_ == tail_){
			Item* tempdel = tail_;
			tail_ = NULL;
			head_ = NULL;
			delete tempdel;
		}
		else if(tail_ != head_){
			Item* deltemp = tail_;
			tail_ = deltemp->prev;
			tail_->next = NULL;
			delete deltemp;
		}
	}

	else if((tail_->last - tail_->first)>1){
		tail_->last = tail_->last -1;
	}

	/*if(head_ == tail_ && (tail_->last - tail_->first == 1)){//checks if the there is just one item in list to delete entire node
		Item* tempdel = tail_;
		tail_ = NULL;
		head_ = NULL;
		delete tempdel;
	}

	
	
	else if(tail_ != head_ && (tail_->last - tail_->first == 1)){
		Item* deltemp = tail_;
		tail_ = deltemp->prev;
		tail_->next = NULL;
		delete deltemp;
	}*/
	size_-=1;
}

std::string const & ULListStr::back() const
{
	return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
	return head_->val[head_->first];
}

/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  

std::string* ULListStr::getValAtLoc(size_t loc) const
{
	if(loc >= size_ || loc<0){
		return NULL;
	}

	else if(loc < size_){ //checks for valid loc
		Item* temphead = head_;
		//size_t headfirst = head_->first;
		//size_t loctemp = 0;
		//while(loctemp != loc)
		while((temphead->last - temphead->first)<=loc){ //>= (temphead->last - temphead->first)){
			loc -= (temphead->last - temphead->first);
			temphead = temphead->next;




		}

		
		return &temphead->val[loc + temphead->first];

	}
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
