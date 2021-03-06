//
// File:        DerivativeCorrelationModel.h
// Package:     MPTCOUPLER kriging algorithm
// 
// 
// 
// Description: Correlation model involving derivatives.
//
// $Id: DerivativeCorrelationModel.h,v 1.1 2005/09/01 16:13:25 knap2 Exp $
//
// $Log: DerivativeCorrelationModel.h,v $
// Revision 1.1  2005/09/01 16:13:25  knap2
// Initial source.
//
//

#if !defined(included_krigalg_DerivativeCorrelationModel)
#define included_krigalg_DerivativeCorrelationModel

#ifndef included_config
#include "asf_config.h"
#endif // included_config

#ifndef included_vector
#define included_vector
#include <vector>
using namespace std;
#endif

#ifndef included_boost_shared_ptr
#define included_boost_shared_ptr
#include <boost/shared_ptr.hpp>
#endif

#include "CorrelationModel.h"

namespace MPTCOUPLER {

  //
  //
  //

  namespace krigalg {

  //
  // forward declarations
  //

  class DerivativeCorrelationModel;
  typedef boost::shared_ptr<DerivativeCorrelationModel> 
    DerivativeCorrelationModelPointer;

  //
  // class definition
  //

  class DerivativeCorrelationModel : public CorrelationModel {

    //
    // methods
    //

  public:
    //
    // construction/destruction
    //

    DerivativeCorrelationModel(const std::vector<double> & thetas);
    virtual ~DerivativeCorrelationModel() = 0;

    //
    // meta-methods
    //

    virtual Matrix getValue(const Point & firstPoint,
			    const Point & secondPoint) const = 0;

    //
    // Database input/output
    //

    virtual std::string getClassName() const = 0;
    virtual void putToDatabase(toolbox::Database & db) const;
    virtual void getFromDatabase(toolbox::Database & db);

  private:
    //
    // copy construction/assignment
    //
    
    DerivativeCorrelationModel(const DerivativeCorrelationModel &);
    const DerivativeCorrelationModel & operator=(const DerivativeCorrelationModel &);

  };

}
}

#endif // included_krigalg_DerivativeCorrelationModel
