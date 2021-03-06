//
//  Color.hpp
//  EWeek3
//
//  Created by CLAYTON WONG on 8/7/18.
//  Copyright © 2018 Clayton Wong. All rights reserved.
//

#pragma once

#include "Byte.hpp"
#include <iostream>

namespace BitmapGraphics
{
   class Color
    {
    public:
    
        using Component = Binary::Byte;
        using Component_t = Binary::Byte_t;
        
        static constexpr int BYTE_COUNT = 3; // one byte per color: red, green, blue
        static constexpr int NIBBLES_PER_BYTE = 2;
        static constexpr int MIN = 0;
        static constexpr int MAX = 255;
        
        static Color read ( std::istream& inStream ) noexcept;
        
        Color() = default;
        ~Color() = default;
        
        template <typename InputType>
        Color ( const InputType& red, const InputType& green, const InputType& blue );
        
        Color ( const std::string& color );
        
        Color ( const Color& src ) = default;
        Color ( Color&& src ) = default;
        
        Color& operator= ( const Color& rhs ) = default;
        Color& operator= ( Color&& rhs ) = default;
        
        const Component_t& getRed() const noexcept;
        const Component_t& getGreen() const noexcept;
        const Component_t& getBlue() const noexcept;
        
        void write ( std::ostream& outStream ) const;
        
        std::string toString ( ) const noexcept;
        
        bool operator== ( const Color& rhs ) const noexcept;
        bool operator!= ( const Color& rhs ) const noexcept;
        
    private:
    
        Component myRed;
        Component myGreen;
        Component myBlue;
    };
    
    template <typename InputType>
    Color::Color ( const InputType& red, const InputType& green, const InputType& blue ) :
    myRed{  static_cast<Component>( red )  },
    myGreen{  static_cast<Component>( green )  },
    myBlue{  static_cast<Component>( blue )  }
    {
    }
    
    std::ostream& operator<< ( std::ostream& outStream, const Color& rhs ) noexcept;
    
} // namespace BitmapGraphics
