// albers specific includes
#include "albers/Registry.h"
#include "albers/Reader.h"

// datamodel specific includes
#include "Jet.h"
#include "JetCollection.h"

  const LorentzVector& JetHandle::P4() const { return m_container->at(m_index).P4();}

  void JetHandle::setP4(LorentzVector value){ m_container->at(m_index).setP4(value);}


bool  JetHandle::isAvailable() const {
  if (m_container != nullptr) {
    return true;
  }
//  else if (m_registry != nullptr){
//    m_registry->getPODAddressFromID(m_containerID,m_container);
//    return true;
//  }
  return false;
}

void JetHandle::prepareForWrite(const albers::Registry* registry){
  m_containerID = registry->getIDFromPODAddress(m_container);
}

void JetHandle::prepareAfterRead(albers::Registry* registry){
  m_registry = registry;
  m_registry->getPODAddressFromID(m_containerID,m_container);
}


JetHandle::JetHandle(int index, int containerID, std::vector<Jet>* container) :
  m_index(index),
  m_containerID(containerID),
  m_container(container)
{}