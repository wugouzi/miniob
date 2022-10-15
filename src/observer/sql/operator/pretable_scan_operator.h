// /*
// **
// ** wefe
// */


// #pragma once

// #include "sql/executor/execute_stage.h"
// #include "sql/expr/tuple.h"
// #include "sql/operator/operator.h"
// #include "storage/record/record_manager.h"
// #include "rc.h"
// #include <vector>

// class Pretable;

// class PretableScanOperator : public Operator
// {
// public:
// PretableScanOperator(Pretable *table)
//     : table_(table), iter_(table->begin())
//   {}

//   virtual ~PretableScanOperator() = default;

//   RC open() override;
//   RC next() override;
//   RC close() override;

//   Tuple *current_tuple() override;

// private:
//   Pretable *table_ = nullptr;
//   std::vector<CompositeTuple*>::iterator iter_;
// };
