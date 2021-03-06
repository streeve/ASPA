//
// File:        InterpolationModelFactory.h
// Package:     MPTCOUPLER kriging algorithm
// 
// 
// 
// Description: Factory class for the creation of the
// Description: InterpolationModel-derived classes.
//
 
#if !defined(included_krigalg_InterpolationModelFactory_h)
#define included_krigalg_InterpolationModelFactory_h
 
#ifndef included_config
#include "asf_config.h"
#endif // included_config
 
#ifndef included_krigalg_InterpolationModel
#include "InterpolationModel.h"
#endif
 
#ifndef included_boost_shared_ptr
#define included_boost_shared_ptr
#include <boost/shared_ptr.hpp>
#endif

#include <string>

namespace MPTCOUPLER {
 
  //
  //
  //
 
  namespace krigalg {

    //
    // forward declarations
    //

    class InterpolationModelFactory;

    //
    // local types
    //

    typedef boost::shared_ptr<InterpolationModelFactory>
      InterpolationModelFactoryPointer;

    /*!
     * @brief Interface for a generic creation of InterpolationModels.
     */

    class InterpolationModelFactory {
      
    public:
      //
      // methods
      //
      
      /*!
       * @brief Destructor.
       */

      virtual ~InterpolationModelFactory() = 0;

      /*!
       * @brief Construct a class based on the class key.
       *
       * @return A pointer to the class instance.
       */
      
      virtual InterpolationModelPtr build() const = 0;

      /*!
       * @brief Get the class key.
       *
       * @return A const pointer to a string containing the class key.
       */

      const std::string & getClassKey() const;


    protected:
      /*!
       * @brief Constructor.
       *
       * @param classKey A key (class name) associated with a class.
       */

      InterpolationModelFactory(const std::string & classKey);

      //
      // data
      //

    private:

      std::string _classKey;

    };

  }

}

#endif // included_krigalg_InterpolationModelFactory_h
