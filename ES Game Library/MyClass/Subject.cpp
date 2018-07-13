#include "Subject.h"
#include "Acceptor.h"

void  Subject::entryAcceptor(Acceptor*  accepter){

	acceptance.push_back(accepter);

}

void  Subject::Notice(Visitor* visitor){
	for (auto acceptor : acceptance){

		acceptor->Accept(visitor);

	}
}