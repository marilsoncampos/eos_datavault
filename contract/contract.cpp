#include <utility>
#include <vector>
#include <string>
#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>
#include <eosiolib/contract.hpp>
#include <eosiolib/time.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/transaction.hpp>

using namespace eosio;

class eosdatavault : public eosio::contract {
public:
  using contract::contract;

  eosdatavault(account_name self) : contract(self) {}

  //@abi action
  void set(const account_name owner,
	   uint64_t id,
	   const std::string data,
	   const std::string pass1) {
    require_auth(owner);

    eosio_assert(1 == 2, "still not implemented");
  }
  
  //@abi action
  void erase(const account_name owner,
	     uint64_t id) {
    require_auth(owner);

    datavault_table table(_self, owner);
    auto itr_data = table.find(id);
    eosio_assert(itr_data != table.end(), "Data not found");
    
    table.erase(itr_data);
  }

  //@abi action
  void add(const account_name owner,
	   const std::string data,
	   const std::string pass1,
	   const std::string alg) {
    require_auth(owner);

    eosio_assert(data.size() > 0, "Empty data");
    eosio_assert(pass1.size() > 0, "Empty pass1");
    
    datavault_table table(_self, owner);
    
    uint64_t newid = table.available_primary_key();
    table.emplace(owner, [&](auto &n) {
      n.id = newid;
      n.data = data;
      n.pass1 = pass1;
      n.alg = alg;
    });
  }

private:

  //@abi table datavault i64
  struct datavault
  {
    uint64_t id;
    std::string data;
    std::string pass1;
    std::string alg;

    uint64_t primary_key() const { return id; }

    EOSLIB_SERIALIZE(datavault, (id)(data)(pass1)(alg))
  };
  typedef eosio::multi_index<N(datavault), datavault> datavault_table;

};

EOSIO_ABI(eosdatavault, (set)(erase)(add))

